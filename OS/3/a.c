
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd1;
  struct stat buff;
  fd1 = stat(argv[1], &buff);
  if (fd1 < 0) {
    perror("Error");
    exit(1);
  }
  printf("Inode no=%d\n", buff.st_ino);
  printf("User no=%d\n", buff.st_uid);
  printf("Grp no=%d\n", buff.st_gid);
  printf("Last  Status=%s\n", ctime(&buff.st_ctim)); printf("Last  Accessed=%s\n", ctime(&buff.st_atim));
  printf("Last  Modified=%s\n", ctime(&buff.st_mtim));
}
