
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int fd1;
  char buff[20];
  fd1 = open("Seek.txt", O_RDWR);
  if (fd1 < 0) {
    perror("Error");
    exit(1);
  }
  read(fd1, buff, 10);
  write(1, buff, 10);
  printf("\n");
  lseek(fd1, 0, SEEK_END);
  read(fd1, buff, 10);
  write(1, buff, 10);
  close(fd1);
}
