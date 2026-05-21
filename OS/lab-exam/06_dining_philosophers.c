#include <pthread.h>
#include <semaphore.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#define PHILOSOPHERS 5

sem_t forks[PHILOSOPHERS];
sem_t room;

void *philosopher(void *arg) {
  int id = (int)(intptr_t)arg;
  int left = id;
  int right = (id + 1) % PHILOSOPHERS;

  printf("Philosopher %d is thinking\n", id + 1);
  sleep(1);

  sem_wait(&room);
  sem_wait(&forks[left]);
  sem_wait(&forks[right]);

  printf("Philosopher %d is eating\n", id + 1);
  sleep(1);

  sem_post(&forks[right]);
  sem_post(&forks[left]);
  sem_post(&room);

  printf("Philosopher %d finished eating\n", id + 1);
  return NULL;
}

int main(void) {
  int i;
  pthread_t thread[PHILOSOPHERS];

  sem_init(&room, 0, PHILOSOPHERS - 1);
  for (i = 0; i < PHILOSOPHERS; i++) {
    sem_init(&forks[i], 0, 1);
  }

  for (i = 0; i < PHILOSOPHERS; i++) {
    pthread_create(&thread[i], NULL, philosopher, (void *)(intptr_t)i);
  }

  for (i = 0; i < PHILOSOPHERS; i++) {
    pthread_join(thread[i], NULL);
  }

  sem_destroy(&room);
  for (i = 0; i < PHILOSOPHERS; i++) {
    sem_destroy(&forks[i]);
  }

  return 0;
}
