#include <stdio.h>
#include <stdlib.h>

/* Libera las 'filas' primeras filas y el vector de punteros. */
static void liberar_matriz(int **m, int filas)
{
    if (m == NULL) {
        return;
    }
    for (int i = 0; i < filas; i++) {
        free(m[i]);
    }
    free(m);
}

/* Reserva una matriz filas x cols. Si algo falla, no deja memoria perdida. */
static int **crear_matriz(int filas, int cols)
{
    int **m = malloc((size_t)filas * sizeof *m);
    if (m == NULL) {
        return NULL;
    }
    for (int i = 0; i < filas; i++) {
        m[i] = malloc((size_t)cols * sizeof *m[i]);
        if (m[i] == NULL) {
            liberar_matriz(m, i); /* solo las filas 0..i-1 existen */
            return NULL;
        }
    }
    return m;
}

/* Devuelve una matriz nueva de c filas y f columnas: m rotada 90 grados horario. */
static int **rotar_derecha(int **m, int f, int c)
{
    int **r = crear_matriz(c, f);
    if (r == NULL) {
        return NULL;
    }
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            r[j][f - 1 - i] = m[i][j];
        }
    }
    return r;
}

static int fila_vacia(const int *fila, int n)
{
    for (int k = 0; k < n; k++) {
        if (fila[k] != 0) {
            return 0;
        }
    }
    return 1;
}

/* Libera las filas de ceros y sube los punteros restantes. Devuelve las filas que quedan. */
static int compactar(int **m, int filas, int cols)
{
    int k = 0;
    for (int i = 0; i < filas; i++) {
        if (fila_vacia(m[i], cols)) {
            free(m[i]);
        } else {
            m[k] = m[i];
            k++;
        }
    }
    return k;
}

static void imprimir_matriz(int **m, int filas, int cols)
{
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s%d", j > 0 ? " " : "", m[i][j]);
        }
        putchar('\n');
    }
}

int main(void)
{
    int f, c;
    if (scanf("%d %d", &f, &c) != 2 || f < 0 || c < 0) {
        printf("ERROR\n");
        return EXIT_FAILURE;
    }
    if (f == 0 || c == 0) {
        printf("VACIA\n");
        return EXIT_SUCCESS;
    }

    int **m = crear_matriz(f, c);
    if (m == NULL) {
        fprintf(stderr, "Sin memoria\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            if (scanf("%d", &m[i][j]) != 1) {
                liberar_matriz(m, f);
                printf("ERROR\n");
                return EXIT_FAILURE;
            }
        }
    }

    int **r = rotar_derecha(m, f, c);
    liberar_matriz(m, f); /* la original ya no hace falta */
    if (r == NULL) {
        fprintf(stderr, "Sin memoria\n");
        return EXIT_FAILURE;
    }

    printf("ROTADA %d x %d\n", c, f);
    imprimir_matriz(r, c, f);

    int k = compactar(r, c, f);
    printf("COMPACTADA %d x %d\n", k, f);
    imprimir_matriz(r, k, f);

    liberar_matriz(r, k); /* las filas vacias ya se liberaron en compactar */
    return EXIT_SUCCESS;
}
