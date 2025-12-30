
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
  int sid, pid;
  struct sockaddr_in se;
  char buff[1000], buff1[1000];

  if (argc != 3) {
    printf("Usage: %s <PORT> <IP>\n", argv[0]);
    exit(1);
  }

  sid = socket(AF_INET, SOCK_STREAM, 0);
  if (sid == -1) {
    perror("SOCKET ERROR");
    exit(1);
  }

  se.sin_family = AF_INET;
  se.sin_port = htons(atoi(argv[1]));
  se.sin_addr.s_addr = inet_addr(argv[2]);

  if (connect(sid, (struct sockaddr *)&se, sizeof(se)) == -1) {
    perror("CONNECT ERROR");
    exit(1);
  }

  pid = fork();

  if (pid == 0) { // CHILD → SEND
    while (1) {

      bzero(buff1, sizeof(buff1));
      printf("Enter Input: ");
      fgets(buff1, sizeof(buff1), stdin);
      send(sid, buff1, strlen(buff1), 0);
    }
  } else { // PARENT → RECEIVE
    while (1) {
      memset(buff, 0, sizeof(buff));
      int n = recv(sid, buff, sizeof(buff), 0);
      if (n <= 0) {
        printf("Server disconnected\n");
        break;
      }
      printf("Received: %s", buff);
    }
  }

  close(sid);
  return 0;
}
