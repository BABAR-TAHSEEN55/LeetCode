
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int sid, a, pid;
  struct sockaddr_in se, cli;
  socklen_t cli_len;
  char buff[1000], buff1[1000];

  if (argc != 3) {
    printf("Usage: %s <PORT> <IP>\n", argv[0]);
    exit(1);
  }

  /* Create socket */
  sid = socket(AF_INET, SOCK_STREAM, 0);
  if (sid == -1) {
    perror("SOCKET ERROR");
    exit(1);
  }

  /* Server address */
  se.sin_family = AF_INET;
  se.sin_port = htons(atoi(argv[1]));
  se.sin_addr.s_addr = inet_addr(argv[2]);

  /* Bind */
  if (bind(sid, (struct sockaddr *)&se, sizeof(se)) == -1) {
    perror("BIND ERROR");
    exit(1);
  }

  /* Listen */
  if (listen(sid, 5) == -1) {
    perror("LISTEN ERROR");
    exit(1);
  }

  printf("Server listening...\n");

  while (1) {
    cli_len = sizeof(cli);
    a = accept(sid, (struct sockaddr *)&cli, &cli_len);
    if (a == -1) {
      perror("ACCEPT ERROR");
      continue;
    }

    pid = fork();

    if (pid == 0) { /* CHILD → RECEIVE */
      close(sid);
      while (1) {
        memset(buff, 0, sizeof(buff));
        int n = recv(a, buff, sizeof(buff), 0);
        if (n <= 0) {
          printf("Client disconnected\n");
          break;
        }
        printf("Received: %s", buff);
      }
      close(a);
      exit(0);
    } else { /* PARENT → SEND */
      while (1) {
        memset(buff1, 0, sizeof(buff1));
        printf("Enter message: ");
        fgets(buff1, sizeof(buff1), stdin);
        send(a, buff1, strlen(buff1), 0);
      }
      close(a);
    }
  }

  close(sid);
  return 0;
}
