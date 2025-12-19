
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<strings.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char *argv[]){
  struct sockaddr_in se,cli;
  int l,a,n,rval,sid,b;
  char buff[1000],buff1[2000];
  if(argc<3){
    perror("WRONG USAGE");
  exit(1);
  }
  sid = socket(AF_INET,SOCK_STREAM,0);
  if(sid==-1){
    perror("SOCK_CRE_ERR");
    exit(1);
  }
  se.sin_family = AF_INET;
  se.sin_addr.s_addr = inet_addr(argv[1]);
  se.sin_port = htons(atoi(argv[1]));

  b = bind(sid,(struct sockdaddr*)&se,sizeof(se));
  if(b==-1){
    perror("SOCK_BIND_ERR");
    exit(1);
  }
  l = listen(sid,5);
  if(l==-1){
    perror("SOCK_LISTEN_ERR");
    exit(1);
  }
  a= accept(sid,(struct sockdaddr *)&cli,sizeof(cli));
  while(1){
    bzero(buff,sizeof(buff));
    recv(a,buff,sizeof(buff),0);
    n=1;
    while(n==1){
      bzero(&buff1,sizeof(buff1));
      fgets(buff1,sizeof(buff1),stdin);
      send(a,buff1,strlen(buff1),0);
      n++;
    }
  }
}

