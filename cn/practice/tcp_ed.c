
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>
int main(int argc, char *argv[]) {
  struct sockaddr_in s;
  int rval, sockid;
  // unsigned long timeval, tempval;
  char m1[20], m2[20];
  system("clear");
  if (argc < 3) {
    printf("WRONG USUAGE");
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
  printf("Enter the Message  :");
  scanf("%s", m1);
  // slen = sizeof(s);
  rval = send(sockid, m1, sizeof(m1), 0);
  if (rval == -1) {
    perror("SOCK_SEND_ERR");
    exit(1);
  }
  rval = recv(sockid, m2, sizeof(m2), 0);
  if (rval == -1) {
    perror("SOCK_RECV_ERR");
    exit(1);
  }
  printf("Received Message : %s", m2);
}
