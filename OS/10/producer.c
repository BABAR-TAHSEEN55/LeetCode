
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int mutex = 1, empty = 3, full = 0, x = 0;
int main() {
  int n;

  int wait();
  int signal();
  void Producer();
  void Consumer();
  printf("1. PRoducer 2.Consumer 3 . Exitll");
  while (1) {

    printf("Enter Choice : ");
    scanf("%d", &n);
    switch (n) {
    case 1:
      if ((mutex == 1 && empty != 0)) {
        Producer();
      } else {
        printf("Buffer is Full\n");
      }
      break;

    case 2:
      if ((mutex == 1 && full != 0)) {
        Consumer();
      } else {
        printf("Buffer is Empty\n");
      }
      break;
    case 3:
      exit(1);
    }
  }
}
int wait(int s) { return (--s); }
int signal(int s) { return (++s); }
void Producer() {
  mutex = wait(mutex);
  full = signal(full);
  empty = wait(empty);
  x++;
  printf("Producer has Producer : %d", x);
  mutex = signal(mutex);
}
void Consumer() {
  mutex = wait(mutex);
  empty = signal(empty);
  full = wait(full);
  printf("Consumer has Consumer : %d", x);
  x--;
  mutex = signal(mutex);
}
