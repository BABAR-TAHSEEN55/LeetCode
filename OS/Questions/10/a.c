
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pid, shmid;
  char *p1;
  shmid = shmget((key_t)150, 100, IPC_CREAT | 0600);
  p1 = (char *)shmat(shmid, 0, 0);
  pid = fork();
  if (pid < 0) {
    perror("Error");
    exit(1);
  }
  if (pid == 0) {
    strcpy(p1, "Demo");
  } else if (pid > 0) {
    wait(NULL);
    printf("Shared Memor y: %s", p1);
  }
}
