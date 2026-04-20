#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>
#include "common.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Uso: %s <N> <modo>\n", argv[0]);
        printf("modo: 1 = sem semaforo (P1), 2 = com semaforo (P2)\n");
        return 1;
    }

    int N = atoi(argv[1]);
    int modo = atoi(argv[2]);

    int shmid = shmget(IPC_PRIVATE, sizeof(counter_t), IPC_CREAT | 0666);
    counter_t *contador = (counter_t*) shmat(shmid, NULL, 0);

    *contador = 0;

    sem_t *sem = NULL;

    if (modo == 2) {
        sem = sem_open("/meu_semaforo", O_CREAT, 0644, 1);
    }

    for (int i = 0; i < N; i++) {
        if (fork() == 0) {
            for (counter_t j = 0; j < TOTAL / N; j++) {
                if (modo == 1) {
                    (*contador)++;
                } else {
                    sem_wait(sem);
                    (*contador)++;
                    sem_post(sem);
                }
            }
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {
        wait(NULL);
    }

    printf("Contador final: %lld\n", *contador);

    if (modo == 2) {
        sem_close(sem);
        sem_unlink("/meu_semaforo");
    }

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}