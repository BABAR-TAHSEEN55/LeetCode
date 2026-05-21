#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

  int fd[2];

  pid_t pid;
  char message[] = "Message sent through pipe";
  char buffer[100];

  if (pipe(fd) == -1) {
    perror("pipe"); 
    return 1;
  }

  pid = fork();

  if (pid < 0) {
    perror("fork");
    return 1;
  }

    /* child -> 0  write  */
    /* parent -> 1  read */



  if (pid == 0) {
    close(fd[0]);
    write(fd[1], message, strlen(message) + 1);
    close(fd[1]);
  } else {
    close(fd[1]);
    read(fd[0], buffer, sizeof(buffer));
    close(fd[0]);
    wait(NULL);
    printf("Parent received: %s\n", buffer);
  }


}
