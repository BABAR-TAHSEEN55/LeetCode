#include<stdio.h>
#include<string.h>

int main(){
char str1[100],str2[100];
  printf("Enter value of String 1 : ");
  fgets(str1,sizeof(str1),stdin);
  str1[strcspn(str1,'\n')]='\0'
  printf("Enter value of String 2 : ");
  fgets(str2,sizeof(st2),stdin);
  str2[strcspn[str2,'\n']]='\0';
printf("Length of the String : %ld",str1)
    char copied[100];
  strcpy(copied,str1);
  printf("Copied string : %s",copied);
  char concat[100];
  strcpy(concat,str2);
  strcat(concat ,str1);
  printf("Concatenation String : %s",concat);
  int cmp = strcmp(str1,str2);
  if(cmp==0){
    printf("Two strings are Equal")
  }else if (cmp>0){
    printf("First String is greater than second")
  }else{}
}
