#include<stdio.h>
# define N 5
int queue[N];
int front =-1;
int rear =-1;

void Enqueue(int x){
  if((front && rear)==N-1){
    printf("Queue is Full");
  }
  front++;
  rear++;
  queue[front]=x;
}
void Dequeue(int x){
  int temp;
  if(rear==-1){
    printf("Queue is Empty");
  }
  temp = queue[rear];
  printf("Dequeue element : %d",temp);
  rear--;
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
