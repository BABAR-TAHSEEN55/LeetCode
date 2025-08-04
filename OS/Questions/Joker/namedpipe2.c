
#include <stdio.h>

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  char str1[100], str2[100];
  int fd;
  fd = mkfifo("fifo1", 0644);
  printf("Named Pipe Created Successfully");
  while (1) {
    fd = open("fifo1", O_WRONLY);
    fgets(str1, 100, stdin);
    write(fd, str1, strlen(str1) + 1);
    close(fd);

    fd = open("fifo1", O_RDONLY);
    read(fd, str2, sizeof(str2));
    printf("User 1 : %s", str1);
    close(fd);
  }
}
