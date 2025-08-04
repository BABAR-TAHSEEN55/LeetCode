
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <unistd.h>

sem_t mutex, rwmutex;
int rc = 0, data = 0;
void *writer(void *arg) {

  intptr_t f;
  f = ((intptr_t)arg);
  sem_wait(&rwmutex);
  data++;
  printf("Writer %d has written %d\n", f, data);
  sleep(1);
  sem_post(&rwmutex);
}

void *reader(void *arg) {
  intptr_t f;
  f = ((intptr_t)arg);
  sem_wait(&mutex);
  rc++;
  if (rc == 1) {
    sem_wait(&rwmutex);
  }
  sem_post(&mutex);

  printf("Reader %d has Read %d\n", f, data);
  sleep(1);
  sem_wait(&mutex);
  rc--;
  if (rc == 0) {
    sem_post(&rwmutex);
  }
  sem_post(&mutex);
}

int main() {
  int i;
  pthread_t wtid[5], rwid[5];
  sem_init(&mutex, 0, 1);
  sem_init(&rwmutex, 0, 1);
  for (i = 0; i < 4; i++) {
    pthread_create(&rwid[i], NULL, writer, (void *)i);
    pthread_create(&wtid[i], NULL, reader, (void *)i);
  }
  for (i = 0; i < 4; i++) {
    pthread_join(wtid[i], NULL);
    pthread_join(rwid[i], NULL);
  }
}
