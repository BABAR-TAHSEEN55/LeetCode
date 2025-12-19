

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<time.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>


int main(int argc , char *argv[]){

struct sockadd_in s,c;
  int sid,sid1,rval,i,n,clen;
  time_t t = time(0);
  char smsg[20];

  strcpy(smsg,ctime(&t));


  sid = socket(AF_INET,SOCK_STREAM,0);
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

  // clients number
  printf("Enter the number of client : ");
  scanf("%d",&n);
  for(int i = 0;i<n;i++){
    clen = sizeof(c);
    sid1=accept(sid,(struct sockadd_r s)&c,clen);
    rval = recv(sid1,smsg,sizeof(smsg),0);
    if(rval==-1){
      perror("SOCK_REC_V_ERR");
      exit(1);
    }
    printf("Message received successfully from %d is %s",i,smsg);
    rval = send(sid1,smsg,sizeof(smsg),0);
  }

}
// Bind the shit
