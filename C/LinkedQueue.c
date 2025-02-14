#include<stdio.h>
#include<stdlib.h>
#define N 100
struct Queue {
  int data;
  struct Queue *link;
};
  struct Queue *rear = NULL;
struct Queue *front = NULL;

void Push(int x){
  struct Queue *newnode= (struct Queue *)(malloc(sizeof(struct Queue)));
  if(newnode==NULL){
    printf("Memory Allocation Failed\n");
    return ;
  }
  newnode->data =x;

  if(front ==NULL){
    front =rear =  newnode;
  }else{
  newnode->link = rear;
  rear = newnode;
  }
}
void Peek(){
  if(front ==NULL){
    printf("Queue is Empty\n");
    return;
  }
  struct Queue *temp;
  temp = front;
  printf("Top Element in the Queue : %d",front->data);
}
void Dequeue(){
  if(front ==NULL){
    printf("Queue is empthy\n");
    return;
  }
  struct Queue *temp;
  temp = front;
  printf("Dequeed Element : %d\n",front->data);
front = front->link;
  free(temp);

}

int main(){
  Push(5);
  Push(9);
  Peek();
}
