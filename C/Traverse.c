#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *left , *right;
};

struct node *create(){
  int x;
  printf("Enter the Value of Node or (Enter -1 for No Node) : ");
  scanf("%d",&x);
  if(x==-1) {
    return NULL;
  }
  struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
  newnode->data=x;
  newnode->left =NULL;
  newnode->right =NULL;
  printf("Enter Left Node Value : %d",x);
  newnode->left = create();

  printf("Enter right Node Value : %d",x);
  newnode->right = create();
  return newnode;
}
void InOrder(struct node *root){
  if(root ==NULL) return ;
InOrder(root->left);
  printf("%d ", root->data);
InOrder(root->right);
}
int main(){
  struct node *root = 0;
  root = create();
  InOrder(root);
}
