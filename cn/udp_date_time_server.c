// Server

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>

int main(int argc, char *argv[]) {
  struct sockaddr_in s, c;
  int sockid, rval, clen;
  if (argc < 3) {
    printf("Wrong Usuage\n");
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
  time_t t;
  rval = bind(sockid, (struct sockaddr *)&s, sizeof(s));
  if (rval == -1) {
    perror("BIND_CRE_ERR");
    exit(1);
  }
  char buffer[20], smesg[20];
  clen = sizeof(c);
  rval =
      recvfrom(sockid, buffer, sizeof(buffer), 0, (struct sockaddr *)&c, &clen);
  if (rval == -1) {
    perror("REC_ERR");
    exit(1);
  }
  printf("Message Received : %s", buffer);
  t = time(0);
  strcpy(smesg, ctime(&t));
  rval =
      sendto(sockid, smesg, sizeof(smesg), 0, (struct sockaddr *)&c, sizeof(c));
  if (rval == -1) {
    perror("Error");
    exit(1);
  }
  printf("Message Send \n");
}

// USE ONLY C rather than  s
// time_t t;
// t  = time(0)
// stcpy(smesg,ctime(&t))->Human Readable Form
