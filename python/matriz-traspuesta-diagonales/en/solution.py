import sys


def read_matrix(text):
    tokens = text.split()
    if not tokens:
        return []
    n = int(tokens[0])
    values = [int(x) for x in tokens[1:1 + n * n]]
    return [values[i * n:(i + 1) * n] for i in range(n)]


def transpose(m):
    n = len(m)
    t = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            t[j][i] = m[i][j]
    return t


def off_diagonal_flows(m):
    return [sum(m[i]) - m[i][i] for i in range(len(m))]


def diagonal_sums(m):
    n = len(m)
    main_sum = 0
    anti_sum = 0
    for i in range(n):
        main_sum += m[i][i]
        anti_sum += m[i][n - 1 - i]
    return main_sum, anti_sum


def asymmetric_pairs(m):
    n = len(m)
    count = 0
    for i in range(n):
        for j in range(i + 1, n):
            if m[i][j] != m[j][i]:
                count += 1
    return count


def max_balance_station(incoming, outgoing):
    best = 0
    best_balance = incoming[0] - outgoing[0]
    for i in range(1, len(incoming)):
        balance = incoming[i] - outgoing[i]
        if balance > best_balance:
            best = i
            best_balance = balance
    return best


def main():
    m = read_matrix(sys.stdin.read())
    if not m:
        print("EMPTY MATRIX")
        return
    t = transpose(m)
    outgoing = off_diagonal_flows(m)
    incoming = off_diagonal_flows(t)
    main_sum, anti_sum = diagonal_sums(m)
    print("TRANSPOSE")
    for row in t:
        print(" ".join(str(x) for x in row))
    print("OUTGOING: " + " ".join(str(x) for x in outgoing))
    print("INCOMING: " + " ".join(str(x) for x in incoming))
    print("INTERNAL: " + str(main_sum))
    print("ANTI_DIAGONAL: " + str(anti_sum))
    print("ASYMMETRIC: " + str(asymmetric_pairs(m)))
    print("MAX_BALANCE: " + str(max_balance_station(incoming, outgoing)))


main()
