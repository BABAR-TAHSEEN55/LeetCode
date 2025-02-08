// Infix To PostFix

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

struct Stack {
  int  top;
  char items[MAX];
};

void Push( struct Stack *s, char ch){
  s->items[++(s->top)]=ch;
}
char Pop(struct Stack *s){
  return (s->top ==-1) ? '\0' : s->items[(s->top)--];
}
char Peep(struct Stack *s){
  return (s->top==-1) ? '\0' : s->items[s->top];
}
int precedence(char ch){
  if(ch=='+' || ch=='-') return 1;
  if(ch=='*' || ch=='/') return 2;
  if(ch=='^') return 3;
  return 0;
}
void InfixToPostFix(char *infix , char *postFix){

struct Stack s = {-1 , {0}};
  int i  = 0; int j = 0;
  while (infix[i]) {
    if(isalnum(infix[i])){
      postFix[j++] = infix[i];
    }else if(infix[i]=='('){
      Push(&s , infix[i]);
    }else if(infix[i]==')'){
      while (Peep(&s)!='(') {
        postFix[j++] = Pop(&s);
      }
      Pop(&s);
    }else{
      while (s.top!=-1 && precedence(Peep(&s))>=precedence(infix[i]) ){
postFix[j++]= Pop(&s);
      }

      Push(&s , infix[i]);
    }
    i++;
  }
  while (s.top!=-1) {
    postFix[j++] = Pop(&s);
  }
  postFix[j] ='\0';
}
int main(){
  char Infix[MAX] , postFix[MAX];
printf("Enter Infix Expression : ");
  scanf("%s", Infix);
  InfixToPostFix(Infix , postFix);
  printf("postFix Expression  : %s\n", postFix );
}

