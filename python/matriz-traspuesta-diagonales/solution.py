import sys


def leer_matriz(texto):
    tokens = texto.split()
    if not tokens:
        return []
    n = int(tokens[0])
    valores = [int(x) for x in tokens[1:1 + n * n]]
    return [valores[i * n:(i + 1) * n] for i in range(n)]


def traspuesta(m):
    n = len(m)
    t = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            t[j][i] = m[i][j]
    return t


def flujos_fuera_diagonal(m):
    return [sum(m[i]) - m[i][i] for i in range(len(m))]


def sumas_diagonales(m):
    n = len(m)
    principal = 0
    secundaria = 0
    for i in range(n):
        principal += m[i][i]
        secundaria += m[i][n - 1 - i]
    return principal, secundaria


def pares_asimetricos(m):
    n = len(m)
    cuenta = 0
    for i in range(n):
        for j in range(i + 1, n):
            if m[i][j] != m[j][i]:
                cuenta += 1
    return cuenta


def estacion_max_balance(entradas, salidas):
    mejor = 0
    mejor_balance = entradas[0] - salidas[0]
    for i in range(1, len(entradas)):
        balance = entradas[i] - salidas[i]
        if balance > mejor_balance:
            mejor = i
            mejor_balance = balance
    return mejor


def main():
    m = leer_matriz(sys.stdin.read())
    if not m:
        print("MATRIZ VACIA")
        return
    t = traspuesta(m)
    salidas = flujos_fuera_diagonal(m)
    entradas = flujos_fuera_diagonal(t)
    principal, secundaria = sumas_diagonales(m)
    print("TRASPUESTA")
    for fila in t:
        print(" ".join(str(x) for x in fila))
    print("SALIDAS: " + " ".join(str(x) for x in salidas))
    print("ENTRADAS: " + " ".join(str(x) for x in entradas))
    print("INTERNOS: " + str(principal))
    print("SECUNDARIA: " + str(secundaria))
    print("ASIMETRICOS: " + str(pares_asimetricos(m)))
    print("MAX_BALANCE: " + str(estacion_max_balance(entradas, salidas)))


main()
