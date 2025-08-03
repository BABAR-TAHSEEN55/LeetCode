
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *run();

int main() {
  int ret1, i;
  pthread_t t1;
  ret1 = pthread_create(&t1, NULL, run, 0);
  if (ret1 == -1) {
    printf("Error");
    exit(1);
  }
  pthread_join(t1, 0);

  for (i = 0; i < 4; i++) {
    printf("Inside main thread\n");
    sleep(2);
  }
}
void *run() {
  for (int i = 0; i < 4; i++) {
    printf("Inside Thread 1\n");
    sleep(2);
  }
  pthread_exit(0);
}
