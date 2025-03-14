#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

int main(){
  struct Node *head=NULL , *newnode,*temp;
  int choice = 1;
  while(choice){
  printf("Enter you choice 1 to continue or 0 to exit??");
  scanf("%d",&choice);
    if(choice ==0) {break;
    }else{
newnode = (struct Node *)(malloc(sizeof(struct Node)));
  printf("Enter the data to be inserted");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
newnode->prev = NULL;
if(head==NULL){
    head=newnode=temp;
  }else{
    temp->next = newnode;
    newnode->prev = temp;
  temp = newnode;
  }

  }
}
  printf("Elements in the Doubly Linked List are : ");
  temp = head;
while(temp!=NULL){
    printf("Element : %d",temp->data);
    temp=temp->next;
  }
}
