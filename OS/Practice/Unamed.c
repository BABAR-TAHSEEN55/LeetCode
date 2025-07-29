
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int a[2], pid;
  char str[40], buff[40];
  pipe(a);
  pid = fork();
  if (pid < 0) {
    printf("Error");
    exit(1);
  } else if (pid == 0) {
    strcpy(str, "Hello World");
    write(a[1], str, strlen(str) + 1);
    printf("child wites");
  } else {
    read(a[0], buff, sizeof(buff)); // 0 For Writing
    printf("Buff has been read by Parennt :%s", buff);
  }
}
// NOTE : A pipe is method in Unix that allows Inter Process Communication
