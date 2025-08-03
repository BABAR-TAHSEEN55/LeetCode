
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

  int pid;
  pid = fork();
  if (pid < 0) {
    perror("Error");
    exit(1);
  }
  if (pid == 0) {
    sleep(5);
    printf("I am Child Process\n");
    printf("MY ID : %d\n", getpid());
    printf("MY Parent : %d\n", getppid());
  } else if (pid > 0) {
    printf("I am Parent Process\n");
    printf("MY ID : %d\n", getpid());
    printf("MY Child : %d\n", pid);
  }
}
