
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
  int sid, b, l, a;
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

  int slen = sizeof(se);
  b = bind(sid, (struct sockaddr *)&se, slen);
  if (b == -1) {
    perror("BIND_ERR");
    exit(1);
  }

  l = listen(sid, 5);
  if (l == -1) {
    perror("LISTEN_ERR");
    exit(1);
  }
  printf("Server is listening...");

  while (1) {
    int clen = sizeof(cli);
    a = accept(sid, (struct sockaddr *)&cli, &clen);
    if (a == -1) {
      perror("ACCEPT_ERR");
      exit(1);
    }

    int pid = fork();
    if (pid == 0) {
      while (1) {
        bzero(&buff, sizeof(buff));
        int n = recv(a, buff, sizeof(buff), 0);
        if (n <= 1) {
          printf("Client disconnected\n");
          break;
        }
        printf("Received data %s", buff);
      }
    } else {
      while (1) {
        bzero(&buff1, sizeof(buff1));
        printf("Enter Input : ");
        fgets(buff1, sizeof(buff1), stdin);
        send(a, buff1, strlen(buff1), 0);
      }
    }
  }
}
