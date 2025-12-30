

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  struct sockaddr_in s;
  unsigned long tempval, timeval;
  int rval, sid;
  socklen_t slen;
  char m1[100], m2[200];
  system("clear");
  if (argc < 3) {
    printf("Wrong Usuage\n");
    exit(1);
  }

  sid = socket(AF_INET, SOCK_DGRAM, 0);
  if (sid == -1) {
    perror("SOCK_CRE_ERR");
    exit(1);
  }
  s.sin_family = AF_INET;
  s.sin_port = htons(atoi(argv[1]));
  s.sin_addr.s_addr = inet_addr(argv[2]);

  printf("Enter input  ");
  scanf("%s", m1);

  slen = sizeof(s);
  rval = sendto(sid, m1, sizeof(m1), 0, (struct sockaddr *)&s, slen);
  printf("Message sent successfully");
  if (rval == -1) {
    perror("SOCK_SEND_ERR");
    exit(1);
  }
  /* strncpy(m2, "", 20); */
  rval =
      recvfrom(sid, &tempval, sizeof(tempval), 0, (struct sockaddr *)&s, &slen);

  if (rval == -1) {
    perror("SOCK_REC_ERRR");
    exit(1);
  }
    timeval = htonl(tempval);
  printf("Message Recieved : :%lu", timeval);
}
