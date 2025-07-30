
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
  int pid, a[2], b[2];
  char str[20], buf1[20], buf2[20];
  pipe(a);
  pipe(b);
  pid = fork();
  if (pid < 0) {
    exit(1);
  }
  if (pid == 0) {
    strcpy(str, "HelloWo");
    write(a[1], str, strlen(str) + 1);
    printf("Child Writes ");
    // Reading
    read(b[0], buf2, sizeof(buf2));
    printf("Child has read : %s", buf2);
  } else {
    sleep(1);
    read(a[0], buf1, sizeof(buf1));
    printf("Parent has Read :%s", buf1);
    strcpy(str, "Super Duper");
    write(b[1], str, strlen(str) + 1);
    printf("ParentkWrites ");
  }
}
