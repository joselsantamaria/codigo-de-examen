import sys


# Index of the minimum of v[lo..hi]. v is increasing and rotated, no duplicates.
def find_pivot(v, lo, hi):
    if v[lo] <= v[hi]:
        return lo
    mid = (lo + hi) // 2
    if v[mid] > v[hi]:
        return find_pivot(v, mid + 1, hi)
    return find_pivot(v, lo, mid)


# Recursive binary search in the sorted range v[lo..hi].
def binary_search(v, x, lo, hi):
    if lo > hi:
        return -1
    mid = (lo + hi) // 2
    if v[mid] == x:
        return mid
    if v[mid] < x:
        return binary_search(v, x, mid + 1, hi)
    return binary_search(v, x, lo, mid - 1)


# Decide which sorted block may contain x and search only there.
def locate(v, x, k):
    if not v:
        return -1
    if k > 0 and v[0] <= x <= v[k - 1]:
        return binary_search(v, x, 0, k - 1)
    return binary_search(v, x, k, len(v) - 1)


def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    v = [int(tok) for tok in data[1:1 + n]]
    q = int(data[1 + n])
    queries = [int(tok) for tok in data[2 + n:2 + n + q]]
    k = find_pivot(v, 0, n - 1) if n > 0 else -1
    out = ['PIVOT ' + str(k)]
    found = 0
    for x in queries:
        i = locate(v, x, k)
        if i != -1:
            found += 1
        out.append(f'{x} {i}')
    out.append(f'FOUND {found}')
    print('\n'.join(out))


if __name__ == '__main__':
    main()
