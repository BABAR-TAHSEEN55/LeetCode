
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
  struct stat buff;
  int fd1;

  fd1 = stat(argv[1], &buff);
  if (fd1 < 0) {
    perror("Error");
    exit(1);
  }
  printf("Inode Id : %d\n", buff.st_ino);
  printf("Group Id : %d\n", buff.st_gid);
  printf("User Id : %d\n", buff.st_uid);
  printf("Modified  : %s\n", ctime(&buff.st_ctime));
  printf("Last Chaned  : %s\n", ctime(&buff.st_atime));
  printf("Last Chaned  : %s:n", ctime(&buff.st_mtime));
}
