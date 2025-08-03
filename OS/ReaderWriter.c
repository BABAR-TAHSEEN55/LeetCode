
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t rwmutex, mutex;
int rc = 0, data = 0;

void *writer(void *arg) {

  intptr_t f;
  f = ((intptr_t)arg);
  sem_wait(&rwmutex);
  data++;
  printf("Writer has %d Written %d  ", data, f);
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
  printf("Reader Has Read : %d", f, data);
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
  pthread_t wtid[5], rtid[5];
  sem_init(&mutex, 0, 1);
  sem_init(&rwmutex, 0, 1);
  for (i = 0; i < 5; i++) {
    pthread_create(&wtid[i], NULL, writer, (void *)i);
    pthread_create(&rtid[i], NULL, reader, (void *)i);
  }
  for (i = 0; i < 5; i++) {
    pthread_join(wtid[i], NULL);
    pthread_join(rtid[i], NULL);
  }
}
