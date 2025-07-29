
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd1;
  struct stat buff;
  fd1 = stat(argv[1], &buff);
  if (fd1 < 0) {
    perror("Error");
    exit(1);
  }
  printf("Inode : %d\n", buff.st_ino);
  printf("User : %d\n", buff.st_uid);
  printf("Group : %d\n", buff.st_gid);
}
