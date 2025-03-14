#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node *next;
};
int main(){
struct Node *head , *newnode,*temp,*traverse;
  newnode= (struct Node *)(malloc(sizeof(struct Node)));
  head = NULL;
  printf("Enter the data to be stored in the newnode");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if(head==NULL){
  head = newnode;
    temp = head;
  }else{
    temp->next = newnode;
    temp = newnode;
  }
  printf("Elements in the SLL are : ");
    traverse=head;
  while(traverse!=NULL){
    printf("%d\n",traverse->data);
   traverse=traverse->next;
  }
}
