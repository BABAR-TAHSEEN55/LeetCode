
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>

int main(int argc,char *argv[]){

  struct sockaddr_in s;
  int rval,sid,slen
  char sym[20],IP[26];
  if(argc<3){
    printf("WRONG");
    exit(1);
  }
  sid = socket(AF_INET,SOCK_DGRAM,0);
  if(sid==-1){
    perror("SOCK_CRE_ERROR");
    exit(1);
  }
  s.sin_family = AF_INET;
  s.sin_addr.s_addr=inet_addr(argv[2]);
  s.sin_port = htons(atoi(argv[2]));
  printf("Enter the symbolic Domain Name");
  scanf("%s",&sym);
  rval = sendto(sid,sym,sizeof(sym),0,(struct sockaddr *)&s,sizeof(s));
  if(rval==-1){
    perror("SOCK_SEND_ERR");
    exit(1);
  }
  printf("Waiting to receive output from the DNS SERVER")
    strcpy(IP,"",20);
  rval = recvfrom(sid,IP,sizeof(IP),0,(struct sockaddr *)&s,sizeof(s));
  if(rval==-1){
    perror("SOCK_SEND_ERR");
    exit(1);
  }
  close(sid);



}
