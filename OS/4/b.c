

#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void *run1();
void *run2();
void *run3();
int main() {
  int ret1, ret2, ret3, i;
  pthread_t t1;
  pthread_t t2;
  pthread_t t3;
  ret1 = pthread_create(&t1, NULL, run1, 0);
  if (ret1 == -1) {
    printf("Error");
    exit(1);
  }
  pthread_join(t1, 0);
  ret2 = pthread_create(&t2, NULL, run2, 0);
  if (ret2 == -1) {
    printf("errro");
    exit(1);
  }
  pthread_join(t2, 0);
  ret3 = pthread_create(&t3, NULL, run3, 0);
  if (ret3 == -1) {
    printf("Error");
    exit(1);
  }
  pthread_join(t3, 0);
  for (i = 0; i < 4; i++) {
    printf("Inside Main\n");
    sleep(2);
  }
}
void *run1() {
  int i;
  for (i = 0; i < 4; i++) {
    printf("Inside Thread 1\n");
    sleep(2);
  }
  pthread_exit(0);
}
void *run2() {
  for (int i = 0; i < 4; i++) {
    printf("Inside Thread 2\n");
    sleep(2);
  }
  pthread_exit(0);
}

void *run3() {
  for (int i = 0; i < 4; i++) {
    printf("Inside Thread 2\n");
    sleep(2);
  }
  pthread_exit(0);
}
