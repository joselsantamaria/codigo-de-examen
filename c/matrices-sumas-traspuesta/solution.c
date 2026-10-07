#include <stdio.h>

#define MAXN 10

/* Lee n*n enteros por filas. Devuelve 1 si los ha leido todos
   y 0 si la entrada se acaba antes. */
static int leerMatriz(int m[MAXN][MAXN], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &m[i][j]) != 1) {
                return 0;
            }
        }
    }
    return 1;
}

static int sumaFila(int m[MAXN][MAXN], int n, int i)
{
    int suma = 0;
    for (int j = 0; j < n; j++) {
        suma += m[i][j];
    }
    return suma;
}

static int sumaColumna(int m[MAXN][MAXN], int n, int j)
{
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += m[i][j];
    }
    return suma;
}

static int traza(int m[MAXN][MAXN], int n)
{
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += m[i][i];
    }
    return suma;
}

static int antidiagonal(int m[MAXN][MAXN], int n)
{
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += m[i][n - 1 - i];
    }
    return suma;
}

static void trasponer(int m[MAXN][MAXN], int n, int t[MAXN][MAXN])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t[j][i] = m[i][j];
        }
    }
}

static int esSimetrica(int m[MAXN][MAXN], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (m[i][j] != m[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(void)
{
    int m[MAXN][MAXN];
    int t[MAXN][MAXN];
    int n;

    if (scanf("%d", &n) != 1 || n < 1 || n > MAXN) {
        printf("N invalido\n");
        return 0;
    }
    if (!leerMatriz(m, n)) {
        printf("Datos incompletos\n");
        return 0;
    }

    printf("Filas:");
    for (int i = 0; i < n; i++) {
        printf(" %d", sumaFila(m, n, i));
    }
    printf("\n");

    printf("Columnas:");
    for (int j = 0; j < n; j++) {
        printf(" %d", sumaColumna(m, n, j));
    }
    printf("\n");

    printf("Traza: %d\n", traza(m, n));
    printf("Antidiagonal: %d\n", antidiagonal(m, n));
    printf("Simetrica: %s\n", esSimetrica(m, n) ? "SI" : "NO");

    trasponer(m, n, t);
    printf("Traspuesta:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", t[i][j]);
        }
        printf("\n");
    }
    return 0;
}
