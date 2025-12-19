
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<strings.h>

int main(int argc, char *argv[])
{
    struct sockaddr_in se;
    int sockid, conn, n;
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
    se.sin_addr.s_addr = inet_addr(argv[1]);
    se.sin_port = htons(atoi(argv[2]));

    conn = connect(sockid, (struct sockaddr*)&se, sizeof(se));
    if (conn == -1) {
        perror("CONN_ERR");
        exit(1);
    }

    while (1) {
        bzero(buff1, sizeof(buff1));
        printf("Enter data to send: ");
        fgets(buff1, sizeof(buff1), stdin);
        send(sockid, buff1, strlen(buff1), 0);

        n = 1;
        while (n == 1) {
            bzero(buff, sizeof(buff));
            recv(sockid, buff, sizeof(buff), 0);
            printf("Received from server: %s\n", buff);
            n++;
        }
    }

    close(sockid);
    return 0;
}
