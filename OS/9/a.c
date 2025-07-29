

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
int mutex = 1, empty = 3, full = 0, x = 0;
int main() {
  int n;
  void Producer();
  void Consumer();
  int wait();
  int signal();
  printf("\n 1. Producer\n 2. Consumer \n 3. Exit\n");
  while (1) {
    printf("Enter your Choice \n");
    scanf("%d", &n);
    switch (n) {
    case 1:
      if ((mutex == 1) && (full != 0)) {
        Producer();
      } else {
        printf("Buffer is Full\n");
        break;
      }
    case 2:
      if ((mutex == 1) && (empty != 0)) {
        Consumer();
      } else {
        printf("Buffer is Empty\n");
        break;
      }
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
  printf("Producer Produced the item : %d\n", x);
  x++;
  mutex = signal(mutex);
}
void Consumer() {

  mutex = wait(mutex);
  full = signal(full);
  empty = wait(empty);
  printf("Consumer Consumed the item : %d\n", x);
  x--;
  mutex = signal(mutex);
}
