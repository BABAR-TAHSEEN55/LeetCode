#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int shmid = shmget(IPC_PRIVATE, 128, IPC_CREAT | 0600);
  pid_t pid;
  char *shared_memory;

  if (shmid < 0) {
    perror("shmget");
    return 1;
  }

  shared_memory = (char *)shmat(shmid, NULL, 0);
  if (shared_memory == (char *)-1) {
    perror("shmat");
    return 1;
  }

  pid = fork();
  if (pid < 0) {
    perror("fork");
    shmdt(shared_memory);
    shmctl(shmid, IPC_RMID, NULL);
    return 1;
  }

  if (pid == 0) {
    strcpy(shared_memory, "Message written in shared memory by child");
    shmdt(shared_memory);
  } else {
    wait(NULL);
    printf("Parent read: %s\n", shared_memory);
    shmdt(shared_memory);
    shmctl(shmid, IPC_RMID, NULL);
  }

  return 0;
}
