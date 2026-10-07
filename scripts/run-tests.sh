#!/usr/bin/env bash
# Compile and run every exercise against its tests/NN.in -> tests/NN.out.
# Usage: scripts/run-tests.sh [c|python]   (default: both)
# Exercises listed in KNOWN_ISSUES.md as excluded are skipped via EXCLUDE (see .gitlab-ci.yml).
set -u
cd "$(dirname "$0")/.."
want="${1:-all}"
tmp="$(mktemp -d)"; trap 'rm -rf "$tmp"' EXIT
pass=0; fail=0

check() { # dir cmd...
  local dir="$1"; shift
  local in out name
  for in in "$dir"/tests/*.in; do
    out="${in%.in}.out"; name="$dir/$(basename "$in" .in)"
    if "$@" < "$in" 2>"$tmp/err" | diff -u "$out" - > "$tmp/diff"; then
      pass=$((pass+1))
    else
      fail=$((fail+1)); echo "FAIL $name"; cat "$tmp/diff"; cat "$tmp/err"
    fi
  done
}

if [ "$want" = all ] || [ "$want" = c ]; then
  for src in c/*/solution.c c/*/en/solution.c; do
    [ -f "$src" ] || continue
    dir="$(dirname "$src")"; bin="$tmp/$(echo "$dir" | tr / _)"
    if gcc -std=c11 -Wall -o "$bin" "$src"; then check "$dir" "$bin"
    else fail=$((fail+1)); echo "FAIL compile $src"; fi
  done
fi
if [ "$want" = all ] || [ "$want" = python ]; then
  for src in python/*/solution.py python/*/en/solution.py; do
    [ -f "$src" ] || continue
    check "$(dirname "$src")" python3 "$src"
  done
fi
echo "passed: $pass failed: $fail"
[ "$fail" -eq 0 ]
