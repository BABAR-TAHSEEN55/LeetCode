#include<stdio.h>
#include <stdlib.h>
#include<ctype.h>
#define MAX 100
struct Stack {
  int top;
int items[MAX];
};
void Push(struct Stack *s , int value){
  if(s->top==MAX-1){
    printf("Stack IS Full");
    return;
  }
  s->items[++(s->top)] = value;
}
int Pop(struct Stack *s){
  return (s->top==-1)? '\0' : s->items[(s->top)--];
}
int EvaluatePostFix(char *postfix){
  struct Stack s;
s.top=-1;
  int i , op1 , op2 , result;
for(int i = 0;postfix[i]!='\0';i++){
    if(isdigit(postfix[i])){
      Push(&s , postfix[i]-'0'); //WHy ?
    }else{
      op2 = Pop(&s);
      op1 = Pop(&s);
      switch(postfix[i]){
        case '+' : result = op1 + op2 ; break;
        case '-': result = op1 - op2;break;
        case '*' : result = op1*op2;break;
        case '/' : if(op2==0){
          printf("Zero Division Error");
          exit(1);
        }
        result = op1/op2;
        break;
          case '^': result = 1;
        for(int j =0;j<op2;j++){
            result*= op2;
            break;
          }
        default: printf("Invalid ");
      }
      Push(&s, result);
    }

  }
  return Pop(&s);
}
int main(){
    char postfix[MAX];

    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    int result = EvaluatePostFix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
