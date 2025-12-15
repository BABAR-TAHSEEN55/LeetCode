
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  struct sockaddr_in s;
  unsigned long timeval, tempval;
  int sockid, slen, rval;
  char m1[20], m2[20];
  if (argc < 3) {
    printf("Wrong Usuage");
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

  printf("Enter the Message : ");
  scanf("%s", m1);
  slen = sizeof(s);

  rval = sendto(sockid, m1, strlen(m1), 0, (struct sockaddr *)&s, slen);
  if (rval == -1) {
    perror("SOCK_SEND_ERROR");
    exit(1);
  }
  strcpy(m2, m1);

  rval = recvfrom(sockid, &tempval, sizeof(tempval), 0, (struct sockaddr *)&s,
                  &slen);
  if (rval == -1) {
    perror("Error");
    exit(1);
  }
  timeval = htonl(tempval);
  printf("%u", timeval);
}
