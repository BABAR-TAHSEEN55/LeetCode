#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid < 0) {
    perror("fork");
    return 1;
  }

  if (pid == 0) {
    printf("Child process\n");
    printf("PID: %d\n", getpid());
    printf("Parent PID: %d\n", getppid());
  } else {
    wait(NULL);
    printf("Parent process\n");
    printf("PID: %d\n", getpid());
    printf("Child PID: %d\n", pid);
  }
}
