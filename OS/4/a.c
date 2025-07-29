
// TODO: : A little bit of doubt
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int pid;
  printf("Demo of Fork\n");
  pid = fork();
  if (pid < 0) {
    perror("Error!!\n");
    exit(1);
  } else if (pid == 0) {
    sleep(2);
    printf("I am a Child Process\n");
    printf("My Pid : %d\n", getpid());
    printf("My Parent : %d\n", getppid());
    sleep(5);
  } else {
    printf("I am a Parent Process");
    printf("My Pid : %d\n", getpid());
    printf("My Child : %d\n", pid);
  }
}
