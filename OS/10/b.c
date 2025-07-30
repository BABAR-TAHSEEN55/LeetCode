
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
  printf("Inode No : %d\n", buff.st_ino);
  printf("User No : %d\n", buff.st_uid);
  printf("Grp No : %d\n", buff.st_gid);
  printf("Link No : %d\n", buff.st_nlink);
  printf("Last Status Changed : %s\n", ctime(&buff.st_ctime));
  printf("Last Status Accessed : %s\n", ctime(&buff.st_atime));
  printf("Last Status Modified : %s\n", ctime(&buff.st_mtime));
}
