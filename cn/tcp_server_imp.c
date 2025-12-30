
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  struct sockaddr_in s, c;
  socklen_t clen;
  int sid, csid;
  char buf[20];

  if (argc != 2) {
    printf("Usage: %s <PORT>\n", argv[0]);
    exit(1);
  }

  sid = socket(AF_INET, SOCK_STREAM, 0);
  if (sid == -1) {
    perror("socket");
    exit(1);
  }

  s.sin_family = AF_INET;
  s.sin_port = htons(atoi(argv[1]));
  s.sin_addr.s_addr = INADDR_ANY;

  bind(sid, (struct sockaddr *)&s, sizeof(s));
  listen(sid, 5);

  printf("Server listening...\n");

  clen = sizeof(c);
  csid = accept(sid, (struct sockaddr *)&c, &clen);

  recv(csid, buf, sizeof(buf) - 1, 0);
  buf[strlen(buf)] = '\0';

  send(csid, "ACK", 4, 0);

  printf("Received: %s\n", buf);
  close(csid);
  close(sid);
  return 0;
}
