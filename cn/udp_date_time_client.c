
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
  char m1[20], m2[20];
  if (argc < 3) {
    printf("Wrong Usage\n");
    exit(1);
  }
  system("clear");
  sockid = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockid == -1) {
    perror("SOCK_CRE_ERR");
    exit(1);
  }
  s.sin_family = AF_INET;
  s.sin_addr.s_addr = inet_addr(argv[1]);
  s.sin_port = htons(atoi(argv[2]));
  slen = sizeof(s);
  printf("Enter the Message : ");
  scanf("%s", m1);
  rval = sendto(sockid, m1, sizeof(m1), 0, (struct sockaddr *)&s, slen);
  if (rval == -1) {
    perror("SOCK_SEND_ERR");
    exit(1);
  }
  strcpy(m2, m1);
  rval = recvfrom(sockid, m2, sizeof(m2), 0, (struct sockaddr *)&s, &slen);
  if (rval == -1) {
    perror("SOCK_RCV_ERR");
    exit(1);
  }
  printf("Received Message : %s", m2);
}
