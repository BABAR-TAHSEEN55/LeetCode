
// TODO HAVE A LOOK
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int main() {
  struct sockaddr_in server, client;
  int sockid, len;
  char buffer[100];

  sockid = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockid == -1) {
    perror("Socket error");
    exit(1);
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(8080); // Use port 8080 (unprivileged)

  if (bind(sockid, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("Bind failed");
    exit(1);
  }

  printf("UDP Echo server running on port 8080...\n");

  len = sizeof(client);
  while (1) {
    int n = recvfrom(sockid, buffer, sizeof(buffer), 0,
                     (struct sockaddr *)&client, &len);
    buffer[n] = '\0';
    printf("Received: %s\n", buffer);
    sendto(sockid, buffer, strlen(buffer), 0, (struct sockaddr *)&client, len);
  }

  /* close(sockid); */
  return 0;
}
