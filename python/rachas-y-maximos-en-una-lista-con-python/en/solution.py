import sys


def average(steps):
    total = 0
    for s in steps:
        total += s
    return total / len(steps)


def peak_position(steps):
    best = 0
    for i in range(1, len(steps)):
        if steps[i] > steps[best]:
            best = i
    return best


def longest_streak(steps, goal):
    current = 0
    best = 0
    for s in steps:
        if s >= goal:
            current += 1
            if current > best:
                best = current
        else:
            current = 0
    return best


def main():
    lines = sys.stdin.read().split('\n')
    n, goal = map(int, lines[0].split())
    if n == 0:
        print('No data')
        return
    steps = [int(x) for x in lines[1].split()]
    pos = peak_position(steps)
    print(f'Days: {n}')
    print(f'Total: {sum(steps)}')
    print(f'Average: {average(steps):.2f}')
    print(f'Peak: {steps[pos]} (day {pos + 1})')
    print(f'Streak: {longest_streak(steps, goal)}')


main()
