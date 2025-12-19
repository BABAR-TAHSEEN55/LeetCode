
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<strings.h>

int main(int argc, char *argv[])
{
    struct sockaddr_in se, cli;
    int sockid, l, a, n, rval;
    socklen_t x;
    char buff[1000], buff1[1000];

    if (argc < 3) {
        printf("USAGE: %s IP PORT\n", argv[0]);
        exit(1);
    }

    sockid = socket(AF_INET, SOCK_STREAM, 0);
    if (sockid == -1) {
        perror("SOCK_CRE_ERR");
        exit(1);
    }

    se.sin_family = AF_INET;
  se.sin_addr.s_addr=inet_addr(argv[2]);
    se.sin_port = htons(atoi(argv[2]));

    rval = bind(sockid, (struct sockaddr*)&se, sizeof(se));
    if (rval == -1) {
        perror("BIND_ERR");
        exit(1);
    }

    l = listen(sockid, 5);
    if (l == -1) {
        perror("LISTEN_ERR");
        exit(1);
    }

    x = sizeof(cli);
    a = accept(sockid, (struct sockaddr*)&cli, &x);
    if (a == -1) {
        perror("ACCEPT_ERR");
        exit(1);
    }

    while (1) {
        bzero(buff, sizeof(buff));
        recv(a, buff, sizeof(buff), 0);
        printf("Received from client: %s\n", buff);

        n = 1;
        while (n == 1) {
            bzero(buff1, sizeof(buff1));
            printf("Enter data to send: ");
            fgets(buff1, sizeof(buff1), stdin);
            send(a, buff1, strlen(buff1), 0);
            n++;
        }
    }

    close(a);
    close(sockid);
    return 0;
}
