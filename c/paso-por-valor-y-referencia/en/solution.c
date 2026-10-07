#include <stdio.h>

/* Pass by value: receives copies and returns a single result. */
static long long to_seconds(int h, int m, int s)
{
    return (long long)h * 3600 + (long long)m * 60 + s;
}

/* Pass by reference: writes three results into the caller's variables. */
static void split_time(long long total, long long *h, long long *m, long long *s)
{
    *h = total / 3600;
    *m = (total % 3600) / 60;
    *s = total % 60;
}

/* In/out parameters: keeps main's running state up to date. */
static void accumulate(long long sec, int stage, long long *total,
                       long long *longest, int *longest_pos)
{
    *total += sec;
    if (sec > *longest) {
        *longest = sec;
        *longest_pos = stage;
    }
}

int main(void)
{
    int n;
    long long total = 0;
    long long longest = -1;
    int longest_pos = 0;
    long long hh = 0, mm = 0, ss = 0;

    if (scanf("%d", &n) != 1 || n < 0) {
        n = 0;
    }

    for (int i = 1; i <= n; i++) {
        int h, m, s;
        if (scanf("%d %d %d", &h, &m, &s) != 3) {
            break;
        }
        long long sec = to_seconds(h, m, s);
        split_time(sec, &hh, &mm, &ss);
        printf("Stage %d: %02lld:%02lld:%02lld\n", i, hh, mm, ss);
        accumulate(sec, i, &total, &longest, &longest_pos);
    }

    split_time(total, &hh, &mm, &ss);
    printf("Total: %02lld:%02lld:%02lld\n", hh, mm, ss);

    if (longest_pos == 0) {
        printf("Longest stage: none\n");
    } else {
        printf("Longest stage: %d\n", longest_pos);
    }
    return 0;
}
