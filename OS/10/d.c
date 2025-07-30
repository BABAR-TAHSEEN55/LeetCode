
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
void *run1();
void *run2();
int main() {
  int ret1, ret2;
  pthread_t t1;
  pthread_t t2;
  ret1 = pthread_create(&t1, NULL, run1, 0);
  if (ret1 == -1) {
    printf("Error ");
    exit(1);
  }
  pthread_join(t1, 0);
  ret2 = pthread_create(&t2, NULL, run2, 0);
  if (ret2 == -1) {
    printf("Error ");
    exit(1);
  }
  pthread_join(t2, 0);
  for (int i = 0; i <= 4; i++) {
    printf("Inside Main Thread\n");
    sleep(2);
  }
}
void *run1() {
  for (int i = 0; i <= 4; i++) {
    printf("Inside Thread 1");
    sleep(2);
  }
  pthread_exit(0);
}

void *run2() {
  for (int i = 0; i <= 4; i++) {
    printf("Inside Thread 2");
    sleep(2);
  }
  pthread_exit(0);
}
