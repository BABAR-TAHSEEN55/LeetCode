#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
struct Stack{
  int top;
  char  items[MAX];
};

void Push(struct Stack *s , char ch){
s->items[++(s->top)]=ch;
}
char Pop(struct Stack *s){
  return s->top==-1?'\0':s->items[(s->top)--];
}
char Peek(struct Stack *s){
  return s->top==-1?'\0':s->items[s->top];
}
int Precedence(char ch){
  if(ch=='+' || ch=='-') return 1;
  if(ch=='*' || ch=='/') return 2;
  if(ch=='^') return 3;
  return 0;
}
void InfixToPostFix(char *postfix , char *infix){
struct Stack s = {-1, {0}};
  int i = 0;
  int j =  0 ;
  while (infix[i]) {
    if(isalnum(infix[i])){
      postfix[j++] =infix[i];
    }else if(infix[i]=='('){
      Push(&s, infix[i]);
    }else if(infix[i]==')'){
      while (Peek(&s)!='(') {
        postfix[j++] = Pop(&s);
      }
      Pop(&s);
    }else{
      while (s.top!=-1 && Precedence(Peek(&s))>=Precedence(infix[i])) {
        postfix[j++] = Pop(&s);
      }
Push(&s , infix[i]);
    }
    i++;
}
  while (s.top!=-1) {
    postfix[j++] = Pop(&s);
  }
  postfix[j] = '\0';
}
int main(){
  char Infix[MAX] , PostFix[MAX];
  printf("Enter Infix Expression : ");
  scanf("%s" ,Infix);
  InfixToPostFix(PostFix, Infix);
  printf("After Evaluation : %s ",PostFix);
}
