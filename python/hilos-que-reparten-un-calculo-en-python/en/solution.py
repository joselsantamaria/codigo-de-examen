import sys
import threading


def summarise(data, start, end, index, results):
    """Compute the summary of data[start:end] and store it in results[index]."""
    if start >= end:
        results[index] = None
        return
    count = 0
    total = 0
    lowest = data[start]
    highest = data[start]
    for k in range(start, end):
        v = data[k]
        count += 1
        total += v
        if v < lowest:
            lowest = v
        if v > highest:
            highest = v
    results[index] = (count, total, lowest, highest)


def fmt(res):
    count, total, lowest, highest = res
    return f"n={count} sum={total} min={lowest} max={highest}"


def main():
    lines = sys.stdin.read().split("\n")
    t, n = map(int, lines[0].split())
    data = []
    if n > 0:
        data = list(map(int, lines[1].split()))

    q, r = divmod(n, t)
    results = [None] * t
    threads = []
    start = 0
    for i in range(t):
        size = q + 1 if i < r else q
        end = start + size
        th = threading.Thread(target=summarise,
                              args=(data, start, end, i, results))
        threads.append(th)
        th.start()
        start = end

    for th in threads:
        th.join()

    out = []
    for i, res in enumerate(results):
        if res is None:
            out.append(f"thread {i}: empty")
        else:
            out.append(f"thread {i}: {fmt(res)}")

    partials = [res for res in results if res is not None]
    if not partials:
        out.append("total: empty")
    else:
        count = sum(p[0] for p in partials)
        total = sum(p[1] for p in partials)
        lowest = min(p[2] for p in partials)
        highest = max(p[3] for p in partials)
        out.append(f"total: {fmt((count, total, lowest, highest))}")
    print("\n".join(out))


main()
