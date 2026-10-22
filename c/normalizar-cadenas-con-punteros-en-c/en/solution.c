#include <stdio.h>
#include <string.h>

#define MAX 201

/* Normalizes s in place and returns the number of words. */
int normalize(char *s) {
    char *r = s; /* read pointer */
    char *w = s; /* write pointer */
    int inWord = 0;
    int words = 0;

    while (*r != '\0') {
        if (*r != ' ') {
            if (!inWord) {
                if (w != s) {
                    *w = ' ';
                    w++;
                }
                words++;
                inWord = 1;
            }
            *w = *r;
            w++;
        } else {
            inWord = 0;
        }
        r++;
    }
    *w = '\0';
    return words;
}

int main(void) {
    char line[MAX];

    if (fgets(line, sizeof line, stdin) == NULL) {
        line[0] = '\0';
    }
    line[strcspn(line, "\n")] = '\0';

    int n = normalize(line);
    printf("[%s]\n%d\n", line, n);
    return 0;
}
