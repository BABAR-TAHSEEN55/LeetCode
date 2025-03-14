#include<stdio.h>
#include<stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
struct Node *head =NULL;
void CreateSll(){
  struct Node *head , *newnode,*temp;
  int choice = 1 , x;
  while(choice){
    printf("Enter 1 to continue or 0 to exit : ");
    scanf("%d",&choice);
    if(choice==0){
      break;
    }else{
  newnode=(struct Node*)(malloc(sizeof(struct Node)));
  if(newnode==NULL){
    printf("Memory Allocation Failed");
      return ;
  }
  printf("Enter the data to be inserted : ");
      scanf("%d",&newnode->data)
  newnode->next= NULL;
  if(head==NULL){
    head =temp= newnode;
  }else{
    temp->next = newnode;
    temp = newnode;
  }
    }
  }
}
void DisplaySLl(){
  struct Node *temp = head;
  if(temp==NULL){
    printf("List  is Empty");
    return;
  }
  while(temp!=0){
    printf("Element : %d ",temp->data);
    temp  = temp->next;
  }
}
void DeleteSllBg(){
  struct Node *temp = head;
  if(temp==NULL){
    printf("List is Empty");
    return;
  }
printf("Deleting the First Element from the SLL : ");
  printf("Deleted element was : %d",head->data);
  head=head->next;
  free(temp);
}
void SearchElement(){
  struct Node *temp= head;
        int element,found;
  printf("Enter the element to be searched : ");
  scanf("%d",&element);
  if(temp==NULL){
    printf("Empty");
    return;
  }
  while(temp!=NULL){
    if(element ==temp->data){
      printf("element is Found ");
found = 1;
      break;
    }
      temp=temp->next;

  }
  if(!found ){
    printf("Element is not FOund");
  }
}
int main(){

}
