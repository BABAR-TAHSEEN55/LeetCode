

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[]) {
  struct sockaddr_in s;
  int rval, sockid;
  unsigned long tempval, timeval;
  char m1[20], m2[20];
  if (argc < 3) {
    printf("Wrong Usuage");
    exit(1);
  }
  sockid = socket(AF_INET, SOCK_STREAM, 0);
  if (sockid == -1) {
    perror("SOCK_CRE_ERR");
    exit(1);
  }
  s.sin_family = AF_INET;
  s.sin_addr.s_addr = inet_addr(argv[1]);
  s.sin_port = htons(atoi(argv[2]));
  rval = connect(sockid, (struct sockaddr *)&s, sizeof(s));
  if (rval == -1) {
    perror("SOCK_CONN_ERR");
    exit(1);
  }
  printf("ENter the message  :");
  scanf("%s", m1);
  rval = send(sockid, m1, sizeof(m1), 0);
  if (rval == -1) {
    perror("SOCK_SEND_ERR");
    exit(1);
  }
  rval = recv(sockid, &tempval, sizeof(tempval), 0);
  if (rval == -1) {
    perror("SOCK_RECV ERR");
    exit(1);
  }
  timeval = htonl(tempval);
  printf("%u", timeval);
}
