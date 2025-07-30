
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char buff[20];
  int fd1, fd2;
  fd1 = open(argv[1], O_RDONLY);
  fd2 = open(argv[2], O_WRONLY | O_CREAT, 0600);
  if (fd1 < 0 || fd2 < 0) {
    printf("Error ff");
    exit(1);
  }
  while (1) {
    int n = read(fd1, buff, 1);
    if (n <= 0) {
      break;
    }
    write(fd2, buff, 1);
  }

  close(fd1);
  close(fd2);
  fd2 = open(argv[2], O_RDONLY);
  if (fd2 < 0) {
    exit(1);
  }
  while (1) {
    int n = read(fd2, buff, 1);
    if (n <= 0) {
      break;
    }
    write(1, buff, 1);
  }
}
