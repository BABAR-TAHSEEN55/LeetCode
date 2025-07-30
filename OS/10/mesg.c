
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <unistd.h>
int main() {
  int pid, msgid;
  char str[30], buff1[20], buff2[20];
  msgid = msgget((key_t)134, IPC_CREAT | 0600);
  pid = fork();
  if (pid == 0) {
    printf("Child Process to parent");
    strcpy(str, "Hello WOrld");
    msgsnd(msgid, str, sizeof(str), 0);
    msgrcv(msgid, buff1, sizeof(buff1), 0, 0);
    printf("Message Received %s", buff1);
  } else if (pid > 0) {

    printf("MEssage fro mparent to Child");
    strcpy(str, "Hola");
    msgsnd(msgid, str, sizeof(str), 0);
    msgrcv(msgid, buff2, sizeof(buff2), 0, 0);
    printf(" Message : received %s\n", buff2);
  }
}
