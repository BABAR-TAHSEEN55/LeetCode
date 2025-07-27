
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int fd;
  int n;
  char buff[20];
  fd = open("f1.txt", O_RDONLY);
  if (fd < 0) {
    perror("Error");
    exit(1);
  }
  read(fd, buff, 10);
  write(1, buff, 10);
  lseek(fd, 10, SEEK_SET);
  read(fd, buff, 10);
  write(1, buff, 10);
  printf("\n");
  close(fd);
}
