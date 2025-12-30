
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  struct sockaddr_in se, cli;
  int sid, c;
  char buff[100], buff1[100];

  system("clear");
  if (argc < 3) {
    printf("Wrong Usuage\n");
    exit(1);
  }
  sid = socket(AF_INET, SOCK_STREAM, 0);
  if (sid == -1) {
    perror("SOCK_CRE_ERR");
    exit(1);
  }
  se.sin_family = AF_INET;
  se.sin_port = htons(atoi(argv[1]));
  se.sin_addr.s_addr = inet_addr(argv[2]);

  c = connect(sid, (struct sockaddr *)&se, sizeof(se));

  int pid = fork();
  if (pid == 0) {
    while (1) {

      bzero(buff1, sizeof(buff1));
      printf("Enter Input : ");
      fgets(buff1, sizeof(buff1), stdin);
      send(sid, buff1, strlen(buff1), 0);
    }
  } else {
    while (1) {
      bzero(buff, sizeof(buff));
      int n = recv(sid, buff, sizeof(buff), 0);
      if (n <= 1) {
        printf("Client disconnected\n");
        break;
      }
      printf("Received data %s", buff);
    }
  }
}
