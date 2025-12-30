
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    unsigned long tempval, timeval;
    struct sockaddr_in s;
    int sid, rval;
    char m1[20];
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
    scanf("%19s", m1);

    sendto(sid, m1, strlen(m1), 0,
           (struct sockaddr *)&s, sizeof(s));

    slen = sizeof(s);

    recvfrom(sid, &tempval, sizeof(tempval), 0,
             (struct sockaddr *)&s, &slen);

    timeval = ntohl(tempval);

    printf("Message received: %lu\n", timeval);

    close(sid);
    return 0;
}
