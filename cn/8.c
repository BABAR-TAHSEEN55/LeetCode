
// Client
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>


int main(int argc , char *argv[]){
struct sockadd_r s;

  int rval,sockid;
  char m1[20];
  socket = socket(AF_INET,SOCK_STREAM,0);
  if(socket==-1){
    perror("SOCK_CRE_ERR");
    exit(1);
  }
  system("clear");
  if(argv<3){
    printf("Wrong Usage");
    exit(1);
  }

  s.sin_family =AF_INET;
  s.sin_addr.s_addr=inet_addr(argv[1]);
  s.sin_port = htons(atoi(argv[2]));

  rval =connect(sockid,(struct sockdaddr)&s,sizeof(s));
  if(rval==-1){
    perror("SOCK_CONN_ERR");
    exit(1);
  }
  rval = recv(sockid,m1,sizeof(m1),0);
  if(rval==-1){
    perror("SOCK_RECV_ERR");
    exit(1);
  }
  close(sockid);



}
