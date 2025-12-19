
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd>
#include<time.h>

int main(int argc,char *argv[]){
  struct sockaddr_in s,c;
  int sid,sid1,rval,n;
  char smesg[20];
  time_t t= time(0); 
  strcpy(smesg,ctime(&t));
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

  b = bind(sid,(struct sockaddr)&s,sizeof(s));
  if(b==-1){
    perror("SOCK_BIND_ERR");
    exit(1);
  }
  l = listen(sid,5);
  printf("Enter the number of clients :")
    scanf("%d",&n);
  for(int i = 0;i<n;i++){
    sid1 = accept(sid,(struct socdaddr)&c,sizeof(c));
    if(sid1==-1){
      perror("SOCK_ACCPET_ERRR")
        exit(1);
    }
    rval = recv(sid1,smesg,sizeof(smesg),0);
    if(rval ==-1){
      perror("SOCK_RECF_ERR")
        exit(1);
    }
    printf("Message received successfully from client %d : %s",i,smesg);
    rval = send(sid1,smesg,sizeof(smesg),0);

    if(rval ==-1){
      perror("SOCK_RECF_ERR")
        exit(1);
    }
  }


}
