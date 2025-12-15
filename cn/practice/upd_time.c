
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
int main(int argc, char *argv[]) {
  struct sockaddr_in s;
  int rval, sockid, slen;
  unsigned long timeval, tempval;
  char m1[20], m2[20];
  system("clear");
  if (argc < 3) {
    printf("WRONG USUAGE");
    exit(1);
  }
  sockid = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockid == -1) {
    perror("SOCK_CRE_ERR");
    exit(1);
  }
  s.sin_family = AF_INET;
  s.sin_addr.s_addr = inet_addr(argv[1]);
  s.sin_port = htons(atoi(argv[2]));
  printf("Enter the Message  :");
  scanf("%s", m1);
  slen = sizeof(s);
  rval = sendto(sockid, m1, sizeof(m1), 0, (struct sockaddr *)&s, slen);
  if (rval == -1) {
    perror("SOCK_SEND_ERR");
    exit(1);
  }
  rval = recvfrom(sockid, &tempval, sizeof(tempval), 0, (struct sockaddr *)&s,
                  &slen);
  if (rval == -1) {
    perror("SOCK_RECV_ERR");
    exit(1);
  }
  timeval = htonl(tempval);
  printf("Message REceived %u", timeval);
}
