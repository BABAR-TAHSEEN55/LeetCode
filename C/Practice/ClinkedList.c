#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
struct Node *head =NULL;
void CreateCll(){
  struct Node *temp , *newnode;
  int choice = 1,x;
  while (choice) {
    printf("Enter the Choice (1 to continue or 0 to exit)");
    scanf("%d",&choice);
    if(choice==0){
      break;
    }else{
      newnode = (struct Node*)(malloc(sizeof(Struct Node)));
      if(newnode==NULL){
        printf("Memory Allocation Failed");
        return;
      }
      printf("Enter the Element to be inserted : ");
      scanf("%d",&newnode->data);
      newnode->next = NULL;
      if(head ==NULL){
        head  = newnode;
        newnode->next = head;
        temp = head;
      }else{
        temp->next = newnode;
        temp = newnode;
        newnode->next = head;
      }
    }
  }
}
