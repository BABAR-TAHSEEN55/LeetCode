
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t rwmutex, mutex;
int rc = 0, data = 0;

void *writer(void *arg) {
    int id = *(int *)arg;
    free(arg);

    sem_wait(&rwmutex);
    data++;
    printf("Writer: Thread %d has written data: %d\n", id, data);
    sleep(1);
    sem_post(&rwmutex);

    return NULL;
}

void *reader(void *arg) {
    int id = *(int *)arg;
    free(arg);

    sem_wait(&mutex);
    rc++;
    if (rc == 1)
        sem_wait(&rwmutex);
    sem_post(&mutex);

    printf("Reader: Thread %d has read data: %d\n", id, data);
    sleep(1);

    sem_wait(&mutex);
    rc--;
    if (rc == 0)
        sem_post(&rwmutex);
    sem_post(&mutex);

    return NULL;
}

int main() {
    pthread_t wtid[5], rtid[5];
    sem_init(&mutex, 0, 1);
    sem_init(&rwmutex, 0, 1);

    for (int i = 0; i < 5; i++) {
        int *arg1 = malloc(sizeof(int));
        int *arg2 = malloc(sizeof(int));
        *arg1 = i;
        *arg2 = i;

        pthread_create(&wtid[i], NULL, writer, arg1);
        pthread_create(&rtid[i], NULL, reader, arg2);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(wtid[i], NULL);
        pthread_join(rtid[i], NULL);
    }

    return 0;
}
