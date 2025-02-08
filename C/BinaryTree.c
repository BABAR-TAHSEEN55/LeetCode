#include<stdio.h>
#include<stdlib.h>

# define N 10
struct node {
  int data ;
  struct node *left , *right;
};
struct node *create(){
  int x;
  struct node *newnode;
  newnode = (struct node *)(malloc(sizeof(struct node)));
  printf("Enter Root Node Value or (Enter -1 for no Node)");
  scanf("%d",&x);
  if(x==-1){
    return 0;
  }
  newnode->data = x;
  printf("Enter Left Node Value");
newnode->left = create();
  printf("Enter Right Node Value");
newnode->right = create();
  return newnode;
}
struct QueueNode {
  struct node *treenode;
  struct QueueNode *next;//For next QueueNode 
};
struct Queue{
  struct QueueNode *front ,*rear;
};
struct QueueNode *create(){
  struct Queue *q  = (struct Queue * )(malloc(sizeof(struct Queue *));
  q->front =q->rear =NULL;
  return q;
}
void Enqueue(struct Queue *q, struct node *treenode){
struct QueueNode *temp = (struct QueueNode *)(malloc(sizeof(struct QueueNode)));
  temp->treenode = treenode;
  temp->next= NULL;
  if(q->rear ==NULL){
    q->front = q->rear = temp;
    return ;
  }
  q->rear->next = temp;
  q->rear = temp;
}
struct node *DeQueue(struct Queue *q){
  if(q->front ==NULL){
    return NULL;
  }
  struct QueueNode *temp = q->front ;
  struct node *treenode = temp->treenode;
  q->front =q->front->next;
  if(q->front ==NULL){
    q->rear = NULL;
  }
  free(temp);
  return treenode;
}
void IsEmpty(struct Queue *q){
  if(q->front ==NULL){
    return ;
  }
}
void BFS ( struct node *root){
  if(root==NULL){
    return;
  }
  struct Queue *q = create();
  Enqueue(q , root);
  while (!IsEmpty) {
    struct node *current = DeQueue(q);
    pritnf("%d",current->data);
  }
  if(current->left){
    Enqueue(q , current->left);
  }
  if(current->right){
    Enqueue(q,current->right);
  }
  pritnf("\n");
  free(q);

}
int main(){
  struct node *root;
  root = 0;
  root=create();
  BFS(root);
}

