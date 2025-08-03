
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
int main() {

  int pid;
  pid = fork();
  if (pid < 0) {
    printf("Error");
    exit(1);
  }
  if (pid == 0) {
    printf("I am a Child Process\n");
    printf("My Id : %d\n", getpid());
    printf("My Parent : %d\n", getppid());
  } else if (pid > 0) {
    printf("I am a Parent Process\n");
    printf("My Id : %d\n", getpid());
    printf("My Child : %d\n", pid);
  }
}
