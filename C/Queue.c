#include<stdio.h>
# define N 5
int queue[N];
int front =-1;
int rear =-1;

void Enqueue(int x){
  if(rear ==-1){
    printf("Queue is Full");
    return;
  }
  if(front ==-1){
    front = 0;
  }
  rear++;
  queue[rear]=x;
}
void Dequeue(int x){
  int temp;
  if(front==-1){
    printf("Queue is Empty");
    return;
  }
  temp = queue[rear];
  printf("Dequeue element : %d",temp);
  front--;
}
void Peek(){
  if(rear==-1){
    printf("Queue is Empty");
  }
  printf("Top Elemetn : %d",queue[rear]);
}
int main(){
  Enqueue(5);
  Enqueue(2);
  Dequeue(2);
  Peek();
}
