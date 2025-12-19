

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/in.h>
#include<netinet.h>
#include<string.h>
#include<time.h>

int main(int argc,char *argv[]){
  struct sockaddr_in s;
  int sid,rval,n,conn;
  char m[20];


if(argc<3){
    exit(1);
    perror("WRONG USUAGE");
  }
  sid = socket(AF_INET,SOCK_STREAM,0);
  if(sid ==-1){
    perror("SOCK_CONN_ERR");
    exit(1);
  }
  s.sin_family = AF_INET;
  s.sin_addr.s_addr =inet_addr(argv[1]);
  s.sin_port = htons(atoi(argv[2]));


  conn= connect(sid,(struct sockaddr)&s,sizeof(s));

  if(conn==-1){
    perror("WW");
    exit(1);
  }
  rval = recv(sid,m,sizeof(m),0);
  if(rval==-1){
    perrro("SS");
    exit(1);
  }
  printf("DATE : %s",m);
  close(sid);




}
