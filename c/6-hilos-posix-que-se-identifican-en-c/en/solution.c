#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 6
#define LIMIT 1000000000LL

typedef struct {
    int id;                 /* logical identifier 1..6 */
    unsigned long long n;   /* input value */
    int steps;              /* result written by the thread */
} Task;

static void *work(void *arg)
{
    Task *t = (Task *)arg;
    unsigned long long x = t->n;
    int steps = 0;

    while (x != 1ULL) {
        if (x % 2ULL == 0ULL) {
            x /= 2ULL;
        } else {
            x = 3ULL * x + 1ULL;
        }
        steps++;
    }
    t->steps = steps;   /* writes only to its own structure */
    return NULL;
}

int main(void)
{
    Task tasks[NUM_THREADS];
    pthread_t threads[NUM_THREADS];

    /* Phase 1: read and validate all the input before creating threads */
    for (int i = 0; i < NUM_THREADS; i++) {
        long long v;
        if (scanf("%lld", &v) != 1 || v < 1 || v > LIMIT) {
            printf("Invalid input\n");
            return 0;
        }
        tasks[i].id = i + 1;
        tasks[i].n = (unsigned long long)v;
        tasks[i].steps = -1;
    }

    /* Phase 2: create all threads, each with its own Task */
    for (int i = 0; i < NUM_THREADS; i++) {
        int err = pthread_create(&threads[i], NULL, work, &tasks[i]);
        if (err != 0) {
            fprintf(stderr, "pthread_create failed (code %d)\n", err);
            for (int j = 0; j < i; j++) {
                pthread_join(threads[j], NULL);
            }
            return 1;
        }
    }

    /* Phase 3: wait for all of them */
    for (int i = 0; i < NUM_THREADS; i++) {
        int err = pthread_join(threads[i], NULL);
        if (err != 0) {
            fprintf(stderr, "pthread_join failed (code %d)\n", err);
            return 1;
        }
    }

    /* Phase 4: print in identifier order */
    int best = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Thread %d: n=%llu steps=%d\n", tasks[i].id, tasks[i].n, tasks[i].steps);
        if (tasks[i].steps > tasks[best].steps) {
            best = i;
        }
    }
    printf("Maximum: thread %d with %d steps\n", tasks[best].id, tasks[best].steps);
    return 0;
}
