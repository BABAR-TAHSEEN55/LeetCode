#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char **argv) {
  struct sockaddr_in s;
  int rval, sockid, slen;
  char m1[20], m2[20];
  system("clear");
  if (argc < 3) {
    printf("\n USUAGE : %s IP-Address PORT#\n", argv[0]);
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
  printf("Enter the Message : \n");
  scanf("%s", m1);
  slen = sizeof(s);
  rval = sendto(sockid, m1, strlen(m1), 0, (struct sockaddr *)&s, slen);
  if (rval == -1) {
    perror("MSG_SEND_ERR");
    exit(1);
  }
  printf("Message sent successfully\n");
  memset(m2, 0, sizeof(m2));
  rval = recvfrom(sockid, m2, sizeof(m2), 0, (struct sockaddr *)&s, &slen);
  if (rval == -1) {
    perror("MSG_RCV_ERROR");
    exit(1);
  }
  printf("Received: %s\n", m2);
  return 0;
}
