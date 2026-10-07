#include <stdio.h>
#include <stdlib.h>

/* Frees the first 'rows' rows and then the pointer array. */
static void free_matrix(int **m, int rows)
{
    if (m == NULL) {
        return;
    }
    for (int i = 0; i < rows; i++) {
        free(m[i]);
    }
    free(m);
}

/* Allocates a rows x cols matrix. On failure it leaks nothing. */
static int **create_matrix(int rows, int cols)
{
    int **m = malloc((size_t)rows * sizeof *m);
    if (m == NULL) {
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        m[i] = malloc((size_t)cols * sizeof *m[i]);
        if (m[i] == NULL) {
            free_matrix(m, i); /* only rows 0..i-1 exist */
            return NULL;
        }
    }
    return m;
}

/* Returns a new cols x rows matrix: m rotated 90 degrees clockwise. */
static int **rotate_right(int **m, int rows, int cols)
{
    int **rot = create_matrix(cols, rows);
    if (rot == NULL) {
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rot[j][rows - 1 - i] = m[i][j];
        }
    }
    return rot;
}

static int row_is_empty(const int *row, int n)
{
    for (int k = 0; k < n; k++) {
        if (row[k] != 0) {
            return 0;
        }
    }
    return 1;
}

/* Frees the all-zero rows and moves the remaining pointers up. Returns the rows left. */
static int compact(int **m, int rows, int cols)
{
    int k = 0;
    for (int i = 0; i < rows; i++) {
        if (row_is_empty(m[i], cols)) {
            free(m[i]);
        } else {
            m[k] = m[i];
            k++;
        }
    }
    return k;
}

static void print_matrix(int **m, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s%d", j > 0 ? " " : "", m[i][j]);
        }
        putchar('\n');
    }
}

int main(void)
{
    int rows, cols;
    if (scanf("%d %d", &rows, &cols) != 2 || rows < 0 || cols < 0) {
        printf("ERROR\n");
        return EXIT_FAILURE;
    }
    if (rows == 0 || cols == 0) {
        printf("EMPTY\n");
        return EXIT_SUCCESS;
    }

    int **m = create_matrix(rows, cols);
    if (m == NULL) {
        fprintf(stderr, "Out of memory\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &m[i][j]) != 1) {
                free_matrix(m, rows);
                printf("ERROR\n");
                return EXIT_FAILURE;
            }
        }
    }

    int **rot = rotate_right(m, rows, cols);
    free_matrix(m, rows); /* the original is no longer needed */
    if (rot == NULL) {
        fprintf(stderr, "Out of memory\n");
        return EXIT_FAILURE;
    }

    printf("ROTATED %d x %d\n", cols, rows);
    print_matrix(rot, cols, rows);

    int k = compact(rot, cols, rows);
    printf("COMPACTED %d x %d\n", k, rows);
    print_matrix(rot, k, rows);

    free_matrix(rot, k); /* empty rows were already freed inside compact */
    return EXIT_SUCCESS;
}
