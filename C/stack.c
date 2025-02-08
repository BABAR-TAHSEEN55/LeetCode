#include<stdio.h>
#define N 5
int stacks[N];
int top = -1;
void push(int x){
if(top==N-1){
    // printf("OverFlow Condition");
  }
  top++;
  stacks[top] = x;
}
void Peek(){
  if(top==-1){
    printf("UnderFlow Condition");
  }
  // printf("Top Element : %d" , stacks[top]);
}
void Pop(int item){
  if(top==-1){
    // printf("Stack is Empty");
  }
  item = stacks[top];
  top--;
  // printf("Popped Element : %d", item );
}
void Display(){
  while(top!=-1){
    printf("Elements in the Stacks are   : %d\n", stacks[top]);
    top--;
  }
}
int main(){
  push(5);
  push(3);
  push(8);
  Display();
  Peek();
}
