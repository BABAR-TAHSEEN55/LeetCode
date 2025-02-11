#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 10
struct Stack {
  int top;
  int items[MAX];
};

void Push(struct Stack *s , int value){
  if(s->top==MAX-1){
    printf("Stack Is Full");
    return 0;
  }
  s->items[++(s->top)] = value;
}
int Pop(struct Stack *s){
  return s->top==-1?'\0':s->items[(s->top)--];
}
int EvaluePostFix(char *postFix){
  int result , int op1 , int op2;
  struct Stack s;
  s.top=-1;
  for(int i = 0;postFix[i]!='\0';i++){
    if(isdigit(postFix[i]){
      Push(&s,postFix[i]-'0')
    }else{
      op2 = Pop(&s);
      op1 = Pop(&s);
      switch (postFix[i]) {
        case '+' : result = op1 + op2;break;
        case '-' : result = op1 - op2;break;
        case '*' : result = op1 *op2;break;
        case '/':if(op2==0){
          printf("InValid");
          return;
        }
        result = op1/op2;break;
        case '^' : 
        for(int j = 0;j<)
      }
    }
  }
}
