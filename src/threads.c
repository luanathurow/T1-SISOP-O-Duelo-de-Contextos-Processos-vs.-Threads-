#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "common.h"

counter_t contador = 0;
int N;

pthread_mutex_t lock;

void* incrementa_sem_mutex(void* arg) {
    for (counter_t i = 0; i < TOTAL / N; i++) {
        contador++;
    }
    return NULL;
}

void* incrementa_com_mutex(void* arg) {
    for (counter_t i = 0; i < TOTAL / N; i++) {
        pthread_mutex_lock(&lock);
        contador++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Uso: %s <N> <modo>\n", argv[0]);
        printf("modo: 1 = sem mutex (T1), 2 = com mutex (T2)\n");
        return 1;
    }

    N = atoi(argv[1]);
    int modo = atoi(argv[2]);

    pthread_t threads[N];

    if (modo == 2) {
        pthread_mutex_init(&lock, NULL);
    }

    for (int i = 0; i < N; i++) {
        if (modo == 1)
            pthread_create(&threads[i], NULL, incrementa_sem_mutex, NULL);
        else
            pthread_create(&threads[i], NULL, incrementa_com_mutex, NULL);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Contador final: %lld\n", contador);

    if (modo == 2) {
        pthread_mutex_destroy(&lock);
    }

    return 0;
}