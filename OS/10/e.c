
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
  int a[2];
  char str[20], buff[20];
  pipe(a);
  int pid = fork();
  if (pid < 0) {
    printf("Error");
    exit(1);
  }
  if (pid == 0) {
    strcpy(str, "Hello!!");
    write(a[1], str, strlen(str) + 1);
    printf("Child writes");
  } else {
    read(a[0], buff, sizeof(buff));
    printf("Parent has read : %s", buff);
  }
}
