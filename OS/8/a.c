
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int a[2], pid;
  char str[40], buf[40];
  pipe(a); // This should be called before fork so that both chld and parent
           // inherits file descriptor
  pid = fork();
  if (pid < 0) {
    printf("Error!");
    exit(1);
  } else if (pid == 0) {
    strcpy(str, "Demo Pipes in Action baby");
    write(a[1], str, strlen(str) + 1); // Includes the Sequence
    printf("I am child Process that writes in PIpe");
  } else {
    read(a[0], buf, sizeof(buf));
    printf("Parent Process has Read : %s", buf);
  }
}
// NOTE : A file Descriptor is a reference number that a program uses to talk to
// a file
