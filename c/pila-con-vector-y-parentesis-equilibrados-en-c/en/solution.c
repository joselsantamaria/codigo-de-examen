#include <stdio.h>
#include <string.h>

#define MAX_STACK 32
#define MAX_LINE 256

typedef struct {
    char data[MAX_STACK];
    int top; /* number of stored elements */
} Stack;

static void stack_init(Stack *s) {
    s->top = 0;
}

static int stack_is_empty(const Stack *s) {
    return s->top == 0;
}

static int stack_is_full(const Stack *s) {
    return s->top == MAX_STACK;
}

static int push(Stack *s, char c) {
    if (stack_is_full(s)) {
        return 0;
    }
    s->data[s->top] = c;
    s->top++;
    return 1;
}

static int pop(Stack *s, char *c) {
    if (stack_is_empty(s)) {
        return 0;
    }
    s->top--;
    *c = s->data[s->top];
    return 1;
}

static char opening_of(char closing) {
    switch (closing) {
    case ')': return '(';
    case ']': return '[';
    case '}': return '{';
    default:  return '\0';
    }
}

static int is_balanced(const char *formula) {
    Stack s;
    char c;
    char top_char;
    stack_init(&s);
    for (size_t i = 0; formula[i] != '\0'; i++) {
        c = formula[i];
        if (c == '(' || c == '[' || c == '{') {
            if (!push(&s, c)) {
                return 0; /* too many openings pending at once */
            }
        } else if (c == ')' || c == ']' || c == '}') {
            if (!pop(&s, &top_char)) {
                return 0; /* closing with no opening */
            }
            if (top_char != opening_of(c)) {
                return 0; /* mismatched kinds */
            }
        }
    }
    return stack_is_empty(&s);
}

int main(void) {
    char line[MAX_LINE];
    int n;

    if (fgets(line, sizeof line, stdin) == NULL) {
        return 0;
    }
    if (sscanf(line, "%d", &n) != 1) {
        return 0;
    }
    for (int k = 1; k <= n; k++) {
        if (fgets(line, sizeof line, stdin) == NULL) {
            line[0] = '\0';
        }
        line[strcspn(line, "\r\n")] = '\0';
        printf("%d: %s\n", k, is_balanced(line) ? "YES" : "NO");
    }
    return 0;
}
