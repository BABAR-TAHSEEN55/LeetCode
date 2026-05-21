#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
sem_t empty_slots;
sem_t filled_slots;
sem_t mutex;

void *producer(void *arg) {
  int item;

  for (item = 1; item <= ITEMS; item++) {
    sem_wait(&empty_slots);
    sem_wait(&mutex);

    buffer[in] = item;
    printf("Produced: %d\n", item);
    in = (in + 1) % BUFFER_SIZE;

    sem_post(&mutex);
    sem_post(&filled_slots);
    sleep(1);
  }

  return NULL;
}

void *consumer(void *arg) {
  int i, item;

  for (i = 0; i < ITEMS; i++) {
    sem_wait(&filled_slots);
    sem_wait(&mutex);

    item = buffer[out];
    printf("Consumed: %d\n", item);
    out = (out + 1) % BUFFER_SIZE;

    sem_post(&mutex);
    sem_post(&empty_slots);
    sleep(1);
  }

  return NULL;
}

int main(void) {
  pthread_t producer_thread, consumer_thread;

  sem_init(&empty_slots, 0, BUFFER_SIZE);
  sem_init(&filled_slots, 0, 0);
  sem_init(&mutex, 0, 1);

  pthread_create(&producer_thread, NULL, producer, NULL);
  pthread_create(&consumer_thread, NULL, consumer, NULL);

  pthread_join(producer_thread, NULL);
  pthread_join(consumer_thread, NULL);

  sem_destroy(&empty_slots);
  sem_destroy(&filled_slots);
  sem_destroy(&mutex);
  return 0;
}
