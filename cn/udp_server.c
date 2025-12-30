
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sid;
  char buf[20];
  struct sockaddr_in s, cli;
  socklen_t len = sizeof(cli);

  sid = socket(AF_INET, SOCK_DGRAM, 0);

  s.sin_family = AF_INET;
  s.sin_port = htons(9090);
  s.sin_addr.s_addr = INADDR_ANY;

  bind(sid, (struct sockaddr *)&s, sizeof(s));

  recvfrom(sid, buf, sizeof(buf), 0, (struct sockaddr *)&cli, &len);

  printf("Received: %s\n", buf);

  sendto(sid, "ACK", 3, 0, (struct sockaddr *)&cli, len);

  close(sid);
  return 0;
}
