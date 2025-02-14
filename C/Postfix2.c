#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX 100
struct Stack {
  int top;
  char items[MAX];
};
void Push(struct Stack *s , int value){
  s->items[++(s->top)] = value;
}
int Pop(struct Stack *s){
  return s->top==-1?'\0' : s->items[(s->top)--];
}
int EvaluatePostFix(char *postfix){
  struct Stack s;
  s.top =-1;
  int result , op1 , op2;
  for(int i = 0;postfix[i]!='\0';i++){
    if(isdigit(postfix[i])){
      Push(&s,postfix[i]-'0');
    }else{
op1 = Pop(&s);
op2 = Pop(&s);
switch (postfix[i]) {
        case '+' : result = op1 + op2 ; break;
        case '-' : result = op1 - op2 ; break;
        case '*' : result = op1 * op2 ; break;
        case '/' :if(op2==0){
          printf("InValid Action");
          exit(1);
        }
          result = op1 * op2 ; break;
        case '^' : result = 1;
          for(int j = 0;j<op1;j++){
            result*=op2;
          }
          break;
            default:
              printf("Invalid Error");
        }
        Push(&s,result);

    }
  }
  return Pop(&s);
}
int main() {
  char PostFix[MAX];
  printf("Enter PostFix Expression : ");
  scanf("%s",PostFix);
  int result = EvaluatePostFix(PostFix);
  printf("After Evauluation : %d\n", result);
}
