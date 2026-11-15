import sys
import threading


def resumir(datos, inicio, fin, indice, resultados):
    """Calcula el resumen de datos[inicio:fin] y lo guarda en resultados[indice]."""
    if inicio >= fin:
        resultados[indice] = None
        return
    cuenta = 0
    suma = 0
    minimo = datos[inicio]
    maximo = datos[inicio]
    for k in range(inicio, fin):
        v = datos[k]
        cuenta += 1
        suma += v
        if v < minimo:
            minimo = v
        if v > maximo:
            maximo = v
    resultados[indice] = (cuenta, suma, minimo, maximo)


def formato(res):
    cuenta, suma, minimo, maximo = res
    return f"n={cuenta} suma={suma} min={minimo} max={maximo}"


def main():
    lineas = sys.stdin.read().split("\n")
    h, n = map(int, lineas[0].split())
    datos = []
    if n > 0:
        datos = list(map(int, lineas[1].split()))

    q, r = divmod(n, h)
    resultados = [None] * h
    hilos = []
    inicio = 0
    for i in range(h):
        tam = q + 1 if i < r else q
        fin = inicio + tam
        t = threading.Thread(target=resumir,
                             args=(datos, inicio, fin, i, resultados))
        hilos.append(t)
        t.start()
        inicio = fin

    for t in hilos:
        t.join()

    salida = []
    for i, res in enumerate(resultados):
        if res is None:
            salida.append(f"hilo {i}: vacio")
        else:
            salida.append(f"hilo {i}: {formato(res)}")

    parciales = [res for res in resultados if res is not None]
    if not parciales:
        salida.append("total: vacio")
    else:
        cuenta = sum(p[0] for p in parciales)
        suma = sum(p[1] for p in parciales)
        minimo = min(p[2] for p in parciales)
        maximo = max(p[3] for p in parciales)
        salida.append(f"total: {formato((cuenta, suma, minimo, maximo))}")
    print("\n".join(salida))


main()
