#include<stdio.h>
#define N 10
int rear = -1;
int front = -1;
int Queue[N];

void Enqueue(int x){
  if(rear==N-1){
  printf("Queue is Full\n");
  }else if(rear == -1 && front ==-1){
    front = rear = 0;
    Queue[rear] = x;
  }else{
    rear++;
    Queue[rear] = x;
    printf("Enqueued Element  : %d",x);
  }
  }

void DeQueue(){
  if(front ==-1 && rear ==-1){
    printf("Queue is Empty\n");
  }else if(front ==rear){
    printf("Dequeued Element : %d",Queue[front]);
    front = rear = -1;
  }else{

    printf("Dequeued Element : %d",Queue[front]);
    front++;
  }
}

int main(){
  Enqueue(5);
  Enqueue(8);
  DeQueue(8);

}
