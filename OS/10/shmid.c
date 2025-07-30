
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>
#include <wait.h>
int main() {
  int pid, shmid;
  char *p1;
  shmid = shmget((key_t)150, 100, IPC_CREAT | 0600);
  p1 = (char *)shmat(shmid, 0, 0);
  pid = fork();
  if (pid == 0) {
    strcpy(p1, "sasdfa");
  } else if (pid > 0) {
    wait(NULL);
    printf("STring : %s", p1);
  }
}
