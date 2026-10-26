#include <stdio.h>

#define MAXD 10

typedef struct {
    int rows;
    int cols;
    int v[MAXD][MAXD];
} Matrix;

static int read_matrix(Matrix *m)
{
    if (scanf("%d %d", &m->rows, &m->cols) != 2) return 0;
    if (m->rows < 1 || m->rows > MAXD || m->cols < 1 || m->cols > MAXD) return 0;
    for (int i = 0; i < m->rows; i++)
        for (int j = 0; j < m->cols; j++)
            if (scanf("%d", &m->v[i][j]) != 1) return 0;
    return 1;
}

/* Circular shift of the columns k positions to the right (k < 0: left). */
static void shift_columns(Matrix *m, int k)
{
    int d = ((k % m->cols) + m->cols) % m->cols;
    if (d == 0) return;
    int row[MAXD];
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++)
            row[(j + d) % m->cols] = m->v[i][j];
        for (int j = 0; j < m->cols; j++)
            m->v[i][j] = row[j];
    }
}

/* Clockwise 90-degree rotation: (i, j) moves to (j, rows-1-i). */
static void rotate_cw(Matrix *m)
{
    Matrix r = {0};
    r.rows = m->cols;
    r.cols = m->rows;
    for (int i = 0; i < m->rows; i++)
        for (int j = 0; j < m->cols; j++)
            r.v[j][m->rows - 1 - i] = m->v[i][j];
    *m = r;
}

static int width_of(int x)
{
    int n = (x <= 0) ? 1 : 0;
    while (x != 0) {
        n++;
        x /= 10;
    }
    return n;
}

static void print_matrix(const Matrix *m)
{
    int w = 1;
    for (int i = 0; i < m->rows; i++)
        for (int j = 0; j < m->cols; j++) {
            int a = width_of(m->v[i][j]);
            if (a > w) w = a;
        }

    printf("Matrix %dx%d:\n", m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            if (j > 0) putchar(' ');
            printf("%*d", w, m->v[i][j]);
        }
        putchar('\n');
    }

    printf("Rows:");
    for (int i = 0; i < m->rows; i++) {
        long long p = 1;
        for (int j = 0; j < m->cols; j++)
            p *= m->v[i][j];
        printf(" %lld", p);
    }
    putchar('\n');

    printf("Columns:");
    for (int j = 0; j < m->cols; j++) {
        long long p = 1;
        for (int i = 0; i < m->rows; i++)
            p *= m->v[i][j];
        printf(" %lld", p);
    }
    putchar('\n');
}

int main(void)
{
    Matrix m = {0};
    int q;

    if (!read_matrix(&m) || scanf("%d", &q) != 1 || q < 0) {
        printf("Invalid input\n");
        return 0;
    }

    for (int t = 0; t < q; t++) {
        char op;
        if (scanf(" %c", &op) != 1) break;
        if (op == 'S') {
            int k;
            if (scanf("%d", &k) != 1) break;
            shift_columns(&m, k);
        } else if (op == 'R') {
            rotate_cw(&m);
        }
    }

    print_matrix(&m);
    return 0;
}
