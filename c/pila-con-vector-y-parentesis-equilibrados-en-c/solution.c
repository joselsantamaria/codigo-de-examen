#include <stdio.h>
#include <string.h>

#define MAX_PILA 32
#define MAX_LINEA 256

typedef struct {
    char datos[MAX_PILA];
    int cima; /* numero de elementos almacenados */
} Pila;

static void pila_iniciar(Pila *p) {
    p->cima = 0;
}

static int pila_vacia(const Pila *p) {
    return p->cima == 0;
}

static int pila_llena(const Pila *p) {
    return p->cima == MAX_PILA;
}

static int apilar(Pila *p, char c) {
    if (pila_llena(p)) {
        return 0;
    }
    p->datos[p->cima] = c;
    p->cima++;
    return 1;
}

static int desapilar(Pila *p, char *c) {
    if (pila_vacia(p)) {
        return 0;
    }
    p->cima--;
    *c = p->datos[p->cima];
    return 1;
}

static char apertura_de(char cierre) {
    switch (cierre) {
    case ')': return '(';
    case ']': return '[';
    case '}': return '{';
    default:  return '\0';
    }
}

static int equilibrada(const char *formula) {
    Pila p;
    char c;
    char tope;
    pila_iniciar(&p);
    for (size_t i = 0; formula[i] != '\0'; i++) {
        c = formula[i];
        if (c == '(' || c == '[' || c == '{') {
            if (!apilar(&p, c)) {
                return 0; /* demasiadas aperturas abiertas a la vez */
            }
        } else if (c == ')' || c == ']' || c == '}') {
            if (!desapilar(&p, &tope)) {
                return 0; /* cierre sin apertura */
            }
            if (tope != apertura_de(c)) {
                return 0; /* tipos distintos */
            }
        }
    }
    return pila_vacia(&p);
}

int main(void) {
    char linea[MAX_LINEA];
    int n;

    if (fgets(linea, sizeof linea, stdin) == NULL) {
        return 0;
    }
    if (sscanf(linea, "%d", &n) != 1) {
        return 0;
    }
    for (int k = 1; k <= n; k++) {
        if (fgets(linea, sizeof linea, stdin) == NULL) {
            linea[0] = '\0';
        }
        linea[strcspn(linea, "\r\n")] = '\0';
        printf("%d: %s\n", k, equilibrada(linea) ? "SI" : "NO");
    }
    return 0;
}
