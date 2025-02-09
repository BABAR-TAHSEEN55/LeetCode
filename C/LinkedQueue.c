#include<stdio.h>
#include<stdlib.h>
#define N 10
struct Queue {
  int data;
  struct Queue *link;
};
struct Queue *rear = 0;
  struct Queue *front  = 0;

void Enqueue(int x){
struct Queue *newnode;
  newnode = (struct Queue *)(malloc(sizeof(struct Queue)));
  newnode->data = x;
newnode->link = 0;
  if(front==0 && rear ==0){
    front = rear = newnode;
  }
  rear->link = newnode;
  rear = newnode;
}

void Peek(){
  struct Queue *temp  = (struct Queue*)(malloc(sizeof(struct Queue)));
  temp = front;
  while (temp!=0) {
    printf("Elements in the Queue are : %d\n", temp->data);
    temp = temp->link;
  }
}
void Pop(){
  struct Queue *temp;
temp = front;
  if(front ==0 ){
    printf("Empty Queue");
    rear = 0;
  }
  printf("Popped Element  : %d\n", front->data);
  front= front->link;
  free(temp);

}

int main(){
  Enqueue(5);
  Enqueue(6);
  Enqueue(59);
  Pop();
  Peek();
}
//TODO : Except Insertion everything takes place through front
