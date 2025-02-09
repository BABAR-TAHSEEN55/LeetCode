#include<stdio.h>
#include<stdlib.h>
#define N 10
struct Stack {
  int data ;
  struct Stack *link;
};
struct Stack *top = 0;

void Push(int x){
struct Stack *newnode;
  newnode = (struct Stack *)(malloc(sizeof(struct Stack)));
  newnode->data = x;
  newnode->link = top;
  top = newnode;
}
void Pop(){
  struct Stack *temp;

  temp = top;
  if(top ==0){
    printf("UnderFlow");
  }
  printf("Popped Element : %d ",top->data);
  top = top->link;
  free(temp);
}
void Display(){
  struct Stack *temp;
  temp =top;
  while (temp!=0) {
    printf("Elements in the Stack are : %d \n",temp->data);
    temp = temp->link;
  }
}
void Peek(){
if(top==0){
    printf("Stack IS Empty");
  }
  printf("Top Element : %d\n",top->data);
}
int main(){
  Push(5);
  Push(3);
  Push(6);
  Display();
  Pop(6);
  Display();
  Peek();
}
