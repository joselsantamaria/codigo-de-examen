#include <stdio.h>

/* Paso por valor: recibe copias y devuelve un unico resultado. */
static long long a_segundos(int h, int m, int s)
{
    return (long long)h * 3600 + (long long)m * 60 + s;
}

/* Paso por referencia: escribe tres resultados en variables del llamador. */
static void descomponer(long long total, long long *h, long long *m, long long *s)
{
    *h = total / 3600;
    *m = (total % 3600) / 60;
    *s = total % 60;
}

/* Paso por referencia de entrada/salida: actualiza el estado de main. */
static void acumular(long long seg, int indice, long long *total,
                     long long *maximo, int *pos_max)
{
    *total += seg;
    if (seg > *maximo) {
        *maximo = seg;
        *pos_max = indice;
    }
}

int main(void)
{
    int n;
    long long total = 0;
    long long maximo = -1;
    int pos_max = 0;
    long long hh = 0, mm = 0, ss = 0;

    if (scanf("%d", &n) != 1 || n < 0) {
        n = 0;
    }

    for (int i = 1; i <= n; i++) {
        int h, m, s;
        if (scanf("%d %d %d", &h, &m, &s) != 3) {
            break;
        }
        long long seg = a_segundos(h, m, s);
        descomponer(seg, &hh, &mm, &ss);
        printf("Tramo %d: %02lld:%02lld:%02lld\n", i, hh, mm, ss);
        acumular(seg, i, &total, &maximo, &pos_max);
    }

    descomponer(total, &hh, &mm, &ss);
    printf("Total: %02lld:%02lld:%02lld\n", hh, mm, ss);

    if (pos_max == 0) {
        printf("Tramo mayor: ninguno\n");
    } else {
        printf("Tramo mayor: %d\n", pos_max);
    }
    return 0;
}
