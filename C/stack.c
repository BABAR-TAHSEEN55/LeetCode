#include<stdio.h>
#define N 5
int stacks[N];
int top = -1;
void push(char x){
if(top==N-1){
    printf("OverFlow Condition");
    return ;
  }
  top++;
  stacks[top] = x;
}
void Peek(){
  if(top==-1){
    printf("UnderFlow Condition");
    return;
  }
  printf("Top Element : %c" , stacks[top]);
}
void Pop(){
  if(top==-1){
    // printf("Stack is Empty");
  }
  char item = stacks[top];
  top--;
  // printf("Popped Element : %d", item );
}
void Display(){
  for(int i =top;i>=0;i--){
    printf("Elements in the Stacks : %c\n", stacks[i]);
  }
}
int main(){
  push('A');
  push('B');
  push('C');
  // Display();
  push('S');
  Display();
  Peek();
}
