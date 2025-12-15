
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
int main(int argc, char *argv[]) {
  struct sockaddr_in s, c;
  int sockid, rval, clen;
  char buffer[20];
  if (argc < 3) {
    printf("WRONG USAGE");
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
  rval = bind(sockid, (struct sockaddr *)&s, sizeof(s));
  if (rval == -1) {
    perror("SOCK_BIND_ERR");
    exit(1);
  }
  clen = sizeof(c);
  rval =
      recvfrom(sockid, buffer, sizeof(buffer), 0, (struct sockaddr *)&c, &clen);
  if (rval == -1) {
    perror("SOCK_RECV_ERR");
    exit(1);
  }

  rval = sendto(sockid, buffer, sizeof(buffer), 0, (struct sockaddr *)&c,
                sizeof(c));
  if (rval == -1) {
    perror("NO");
    exit(1);
  }
}
