import sys


def lower_bound(v, x):
    """First index i with v[i] >= x (len(v) if none exists)."""
    lo, hi = 0, len(v)
    while lo < hi:
        mid = (lo + hi) // 2
        if v[mid] < x:
            lo = mid + 1
        else:
            hi = mid
    return lo


def upper_bound(v, x):
    """First index i with v[i] > x (len(v) if none exists)."""
    lo, hi = 0, len(v)
    while lo < hi:
        mid = (lo + hi) // 2
        if v[mid] <= x:
            lo = mid + 1
        else:
            hi = mid
    return lo


def answer(swipes, a, b):
    """Return (count, earliest) for the interval [a, b]."""
    if a > b:
        return 0, None
    i = lower_bound(swipes, a)
    j = upper_bound(swipes, b)
    if i >= j:
        return 0, None
    return j - i, swipes[i]


def main():
    data = sys.stdin.read().split()
    if not data:
        return
    n = int(data[0])
    swipes = sorted(int(t) for t in data[1:1 + n])
    pos = 1 + n
    q = int(data[pos])
    pos += 1
    out = []
    for _ in range(q):
        a = int(data[pos])
        b = int(data[pos + 1])
        pos += 2
        count, earliest = answer(swipes, a, b)
        text = str(earliest) if earliest is not None else "-"
        out.append(str(count) + " " + text)
    if out:
        sys.stdout.write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
