
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  int pid, a[20];
  char buff[20], str[20];
  pipe(a);
  pid = fork();
  if (pid < 0) {
    perror("Error");
    exit(1);
  }

  if (pid == 0) {
    strcpy(str, "Demo of Pipes");
    write(a[1], str, strlen(str) + 1);
    printf("Child Has Written ");
  } else if (pid > 0) {
    read(a[0], buff, sizeof(buff));
    printf("Parent has Read %s", buff);
  }
}
