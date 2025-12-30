
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
  socklen_t slen;
  int sid, rval;
  char m1[20], m2[20];

  sid = socket(AF_INET, SOCK_STREAM, 0);
  if (sid == -1) {
    perror("SOCK_CRE_ERR");
    exit(1);
  }
  s.sin_family = AF_INET;
  s.sin_port = htons(atoi(argv[1]));
  s.sin_addr.s_addr = inet_addr(argv[2]);

  printf("Enter message : ");
  scanf("%s", m1);

  slen = sizeof(s);
  rval = connect(sid, (struct sockaddr *)&s, slen);
  if (rval == -1) {
    perror("SOCK+_CRE_ERR");
    exit(1);
  }
  rval = send(sid, m1, sizeof(m1), 0);
  if (rval == -1) {
    perror("SOCK_SEND_ERR");
    exit(1);
  }
  strncpy(m2, "", 20);
  rval = recv(sid, m2, sizeof(m2), 0);
  if (rval == -1) {
    perror("SOCK_SEND_ERR");
    exit(1);
  }
  printf("Message recieved :%s", m2);
}
