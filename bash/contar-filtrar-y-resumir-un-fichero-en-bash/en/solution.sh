#!/usr/bin/env bash
# Lab usage summary: main.sh [-r ROOM] [-m MINUTES] < log
set -u
export LC_ALL=C

usage() {
    echo "usage: main.sh [-r ROOM] [-m MINUTES]" >&2
    exit 2
}

room=""
minimum=0
while getopts ":r:m:" opt; do
    case "$opt" in
        r) room="$OPTARG" ;;
        m) minimum="$OPTARG" ;;
        *) usage ;;
    esac
done
shift $((OPTIND - 1))

[ "$#" -eq 0 ] || usage
[[ "$minimum" =~ ^[0-9]+$ ]] || usage

awk -F: -v room="$room" -v minimum="$minimum" '
BEGIN { threshold = minimum + 0 }
/^[ \t]*$/ || /^#/ { next }
NF != 3 || $1 !~ /^[a-z0-9]+$/ || $2 !~ /^[A-Za-z0-9]+$/ || $3 !~ /^[0-9]+$/ {
    invalid++
    next
}
room != "" && $2 != room { next }
{
    records++
    total += $3
    minutes[$1] += $3
    sessions[$1]++
}
END {
    for (u in minutes) {
        if (minutes[u] >= threshold) {
            printf "1\t%s %d %d\n", u, minutes[u], sessions[u]
            shown++
        }
    }
    printf "2a\trecords: %d\n", records
    printf "2b\tinvalid: %d\n", invalid
    printf "2c\ttotal: %d\n", total
    printf "2d\tusers: %d\n", shown
}' | sort | cut -f2-
