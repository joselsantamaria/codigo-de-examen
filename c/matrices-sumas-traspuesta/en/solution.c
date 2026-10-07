#include <stdio.h>

#define MAXN 10

/* Reads n*n integers row by row. Returns 1 if all of them were read
   and 0 if the input ends early. */
static int readMatrix(int m[MAXN][MAXN], int n)
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

static int rowSum(int m[MAXN][MAXN], int n, int i)
{
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += m[i][j];
    }
    return sum;
}

static int columnSum(int m[MAXN][MAXN], int n, int j)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += m[i][j];
    }
    return sum;
}

static int trace(int m[MAXN][MAXN], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += m[i][i];
    }
    return sum;
}

static int antidiagonal(int m[MAXN][MAXN], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += m[i][n - 1 - i];
    }
    return sum;
}

static void transpose(int m[MAXN][MAXN], int n, int t[MAXN][MAXN])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            t[j][i] = m[i][j];
        }
    }
}

static int isSymmetric(int m[MAXN][MAXN], int n)
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
        printf("Invalid N\n");
        return 0;
    }
    if (!readMatrix(m, n)) {
        printf("Incomplete data\n");
        return 0;
    }

    printf("Rows:");
    for (int i = 0; i < n; i++) {
        printf(" %d", rowSum(m, n, i));
    }
    printf("\n");

    printf("Columns:");
    for (int j = 0; j < n; j++) {
        printf(" %d", columnSum(m, n, j));
    }
    printf("\n");

    printf("Trace: %d\n", trace(m, n));
    printf("Antidiagonal: %d\n", antidiagonal(m, n));
    printf("Symmetric: %s\n", isSymmetric(m, n) ? "YES" : "NO");

    transpose(m, n, t);
    printf("Transpose:\n");
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
