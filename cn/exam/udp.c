
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  struct sockaddr_in s;
  int sid, rval;
  char m1[20], m2[20];
  socklen_t slen;

  if (argc != 3) {
    printf("Usage: %s <PORT> <IP>\n", argv[0]);
    exit(1);
  }

  sid = socket(AF_INET, SOCK_DGRAM, 0);
  if (sid == -1) {
    perror("SOCKET ERROR");
    exit(1);
  }

  s.sin_family = AF_INET;
  s.sin_port = htons(atoi(argv[1]));
  s.sin_addr.s_addr = inet_addr(argv[2]);

  printf("Enter data: ");
  scanf("%s", m1);

  rval = sendto(sid, m1, sizeof(m1), 0, (struct sockaddr *)&s, sizeof(s));
  if (rval == -1) {
    perror("SEND ERROR");
    exit(1);
  }

  strncpy(m2, "", 20);
  slen = sizeof(s);

  rval = recvfrom(sid, m2, sizeof(m2), 0, (struct sockaddr *)&s, &slen);
  if (rval == -1) {
    perror("RECV ERROR");
    exit(1);
  }

  printf("Message received: %s\n", m2);
  close(sid);
  return 0;
}
