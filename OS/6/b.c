

#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int pid = fork();
  printf("Fork in the chat baby!");

  if (pid < 0) {
    printf("Error !!");
    exit(1);
  } else if (pid == 0) {
    system("ps -l");
    printf("I am a freaking Child Process\n");
    printf("My Pid : %d\n", getpid());
    printf("My Parent Pid : %d\n", getppid());
    ;
  } else {
    sleep(2);
    system("ps -l");
    printf("I am a freaking Parent Process\n");
    printf("My Pid : %d\n", getpid());
    printf("My Child Pid : %d\n", pid);
  }
}
