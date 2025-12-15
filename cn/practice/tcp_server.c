
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  struct sockaddr_in s, c;
  int rval, sockid, sockRoom, clen;
  char buffer[20];
  if (argc < 3) {
    printf("WRONG USUAGE\n");
    exit(1);
  }
  system("clear");
  sockid = socket(AF_INET, SOCK_STREAM, 0);
  if (sockid == -1) {
    perror("SOCK_CRE_ERR");
    exit(1);
  }
  s.sin_family = AF_INET;
  s.sin_addr.s_addr = inet_addr(argv[1]);
  s.sin_port = htons(atoi(argv[2]));
  rval = bind(sockid, (struct sockaddr *)&s, sizeof(s));
  if (rval == -1) {
    perror("SOCK_BIND_ERR");
    exit(1);
  }
  rval = listen(sockid, 5);
  if (rval == -1) {
    perror("SOCK_LIS_ERR");
    exit(1);
  }
  clen = sizeof(c);
  sockRoom = accept(sockid, (struct sockaddr *)&c, &clen);
  if (sockRoom == -1) {

    exit(1);
  }
  rval = recv(sockRoom, buffer, sizeof(buffer), 0);
  if (rval == -1) {
    perror("SOCK_RECV_ERR");
    exit(1);
  }
  rval = send(sockRoom, buffer, sizeof(buffer), 0);
  if (rval == -1) {
    perror("SOCK_SEND_ERR");
    exit(1);
  }
}
