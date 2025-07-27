
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#define BUFFSIZE 1024

/* int main() { */
/*   int fd1, n; */
/*   char buff[BUFFSIZE]; */
/*   fd1 = open("f1.txt", O_RDONLY); */
/*   if (fd1 < 0) { */
/*     perror("Error while opening File"); */
/*     exit(1); */
/*   } */
/*   n = read(fd1, buff, BUFFSIZE); */
/*   if (n == -1) { */
/*     perror("No Content inside File"); */
/*     exit(1); */
/*   } */
/*   printf("n=%d", n); */
/*   close(fd1); */
/* } */
int main() {
  int fd1, fd2, n;
  char buff[20];
  fd1 = open("f1.txt", O_RDONLY);
  if (fd1 < 0) {
    perror("Error");
    exit(1);
  }
  fd2 = open("f2.txt", O_WRONLY | O_APPEND);
  if (fd2 < 0) {
    perror("Error");
    exit(1);
  }
  while ((n = read(fd1, buff, 20)) != 0) {
    write(fd2, buff, n);
  }
  close(fd1);
  close(fd2);
}
