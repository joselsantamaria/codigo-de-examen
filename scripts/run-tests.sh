#!/usr/bin/env bash
# scaffold-version: 2
# Compile and run every exercise against its tests/NN.in -> tests/NN.out.
# Usage: scripts/run-tests.sh [language ...]   (c cpp java python javascript sql bash asm; default: all)
# A test may add tests/NN.args: one command-line argument per line.
# Trailing spaces and trailing blank lines are ignored when comparing.
set -u
cd "$(dirname "$0")/.."
if [ $# -eq 0 ]; then set -- all; fi
wanted="$*"
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
pass=0
fail=0
units=0

norm() {
  awk '{ sub(/[ \t\r]+$/, ""); l[NR] = $0 } END { n = NR; while (n > 0 && l[n] == "") n--; for (i = 1; i <= n; i++) print l[i] }'
}

limit() {
  if command -v timeout > /dev/null 2>&1; then timeout 10 "$@"; else "$@"; fi
}

# check <dir> <command...>: run the command on every <dir>/tests/NN.in.
check() {
  dir="$1"
  shift
  for in in "$dir"/tests/*.in; do
    [ -f "$in" ] || continue
    base="$(echo "$in" | sed 's/[.]in$//')"
    name="$dir/$(basename "$base")"
    (
      if [ -f "$base.args" ]; then
        while IFS= read -r line || [ -n "$line" ]; do set -- "$@" "$line"; done < "$base.args"
      fi
      limit "$@" < "$in" > "$tmp/actual" 2> "$tmp/err"
    )
    if diff -u "$base.out" "$tmp/actual" > /dev/null 2>&1 || diff -u <(norm < "$base.out") <(norm < "$tmp/actual") > "$tmp/diff"; then
      pass=$((pass + 1))
    else
      fail=$((fail + 1))
      echo "FAIL $name"
      cat "$tmp/diff"
      cat "$tmp/err"
    fi
  done
}

# run_language <language> <solution file name>
run_language() {
  language="$1"
  file="$2"
  case " $wanted " in
    *" all "*|*" $language "*) ;;
    *) return 0 ;;
  esac
  [ -d "$language" ] || return 0
  for src in $(find "$language" -name "$file" -not -path '*/.*' | sort); do
    dir="$(dirname "$src")"
    id="$(echo "$dir" | tr / _)"
    units=$((units + 1))
    ok=1
    case "$language" in
      c) gcc -std=c17 -O2 -Wall -o "$tmp/$id" "$src" -lm -lpthread || ok=0 ;;
      cpp) g++ -std=c++20 -O2 -Wall -o "$tmp/$id" "$src" -lpthread || ok=0 ;;
      asm) gcc -no-pie -o "$tmp/$id" "$src" || ok=0 ;;
      java) mkdir -p "$tmp/$id" && javac -encoding UTF-8 -d "$tmp/$id" "$src" || ok=0 ;;
    esac
    if [ "$ok" -eq 0 ]; then
      fail=$((fail + 1))
      echo "FAIL compile $src"
      continue
    fi
    case "$language" in
      c|cpp|asm) check "$dir" "$tmp/$id" ;;
      java) check "$dir" java -cp "$tmp/$id" Main ;;
      python) check "$dir" python3 -B "$src" ;;
      javascript) check "$dir" node "$src" ;;
      sql) check "$dir" python3 scripts/sqlrun.py "$src" ;;
      bash) check "$dir" bash "$src" ;;
    esac
  done
}

run_language c solution.c
run_language cpp solution.cpp
run_language java Main.java
run_language python solution.py
run_language javascript solution.js
run_language sql solution.sql
run_language bash solution.sh
run_language asm solution.s

echo "exercises: $units passed: $pass failed: $fail"
[ "$fail" -eq 0 ]
