#include <stdio.h>

#define MAXD 6

/* Reads m, n and the matrix in row-major order. Returns 1 on success. */
static int read_matrix(long long a[MAXD][MAXD], int *m, int *n)
{
    if (scanf("%d %d", m, n) != 2) return 0;
    if (*m < 1 || *m > MAXD || *n < 1 || *n > MAXD) return 0;
    for (int i = 0; i < *m; i++)
        for (int j = 0; j < *n; j++)
            if (scanf("%lld", &a[i][j]) != 1) return 0;
    return 1;
}

/* prod[j] = product of the entries of column j. */
static void column_products(long long a[MAXD][MAXD], int m, int n,
                            long long prod[MAXD])
{
    for (int j = 0; j < n; j++) {
        prod[j] = 1;
        for (int i = 0; i < m; i++)
            prod[j] *= a[i][j];
    }
}

/* Bareiss fraction-free elimination. Modifies a, returns the rank
   and stores in *sign (+1 or -1) the effect of the row swaps. */
static int bareiss(long long a[MAXD][MAXD], int m, int n, int *sign)
{
    int r = 0;
    long long prev = 1;
    *sign = 1;
    for (int col = 0; col < n && r < m; col++) {
        int p = r;
        while (p < m && a[p][col] == 0)
            p++;
        if (p == m)
            continue;                 /* no pivot in this column */
        if (p != r) {
            for (int j = 0; j < n; j++) {
                long long t = a[p][j];
                a[p][j] = a[r][j];
                a[r][j] = t;
            }
            *sign = -*sign;
        }
        for (int i = r + 1; i < m; i++) {
            for (int j = col + 1; j < n; j++)
                a[i][j] = (a[i][j] * a[r][col] - a[i][col] * a[r][j]) / prev;
            a[i][col] = 0;
        }
        prev = a[r][col];
        r++;
    }
    return r;
}

int main(void)
{
    long long a[MAXD][MAXD];
    long long prod[MAXD];
    int m, n, sign;

    if (!read_matrix(a, &m, &n)) {
        printf("invalid input\n");
        return 0;
    }

    column_products(a, m, n, prod);
    printf("products:");
    for (int j = 0; j < n; j++)
        printf(" %lld", prod[j]);
    printf("\n");

    int rank = bareiss(a, m, n, &sign);
    printf("rank: %d\n", rank);

    if (m != n)
        printf("determinant: undefined\n");
    else if (rank < m)
        printf("determinant: 0\n");
    else
        printf("determinant: %lld\n", sign * a[m - 1][m - 1]);
    return 0;
}
