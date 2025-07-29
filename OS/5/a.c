
// TODO : Check it once again
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void *run1();

int main() {
  int ret1;
  pthread_t t1;
  ret1 = pthread_create(&t1, NULL, run1, 0);
  if (ret1 == -1) {
    printf("Error");
    exit(1);
  }
  pthread_join(t1, 0);
  for (int i = 0; i < 4; i++) {
    printf("Inside Main thread\n");
    sleep(2);
  }
}
void *run1() {
  for (int i = 0; i < 4; i++) {
    printf("Inside Thread1");
    sleep(2);
  }
  pthread_exit(0);
}
