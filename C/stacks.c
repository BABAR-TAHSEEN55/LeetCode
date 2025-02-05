#include <stdio.h>
#include <cstdlib>
struct node {
  int data ;
  struct node *next;
};
struct node *top = 0;
// // #define N 5
// // int stacks[N];
// // int top = -1;
// //
// //
// // void push(int x){
// //   if(top==N-1){
// //     printf("Stack is Full");
// //   }else{
// //     top++;
// // stacks[top]=x;
// //   }
// // }
// // void pop(int x){
// //   if(top==-1){
// //     printf("UnderFlow");
// //   }else{
// //     x = stacks[top];
// //     top--;
// //     printf("Value Of Popped Items : %d",x);
// //   }
// // }
// //
// // void peep(){
// //   if(top==-1){
// //     printf("Stack is Empty\n");
// //   }else{
// //     printf("Top Element :%d",stacks[top]);
// //   }
// // }
// // int main(){
// //   push(5);
// //   peep();
// //
// //   push(4);
// //   push(3);
// //   pop(3);
// //   peep();
// // }
// int main(){
//
// struct node {
//   int data;
//   struct node *next;
// };
// struct node *head , *newnode;
// newnode = (struct node *)(malloc(sizeof(struct node)));
// printf("Enter Data \n");
// scanf("%d",&newnode->data);
// newnode->data=0;
//   if(head==0){
//     head=newnode;
//   }
//   printf("%d",newnode);
// }
//

void push (int x ){
  struct node *newnode;
newnode = (struct node *)(malloc(sizeof(struct node)));
  newnode->data=x;
  newnode->next=top;
  top = newnode;
}
void Display(){
  struct node *temp;
  temp = top;
  while(temp!=0){
    printf("Value : %d\n",temp->data);
    temp=temp->next;
  }
}
void Peek(){
  if(top==0){
    printf("Stack is Empty");
  }else{
    printf("Top element :%d ",top->data);
  }
}
void pop(){
  struct node *temp;
  temp=top;
  if(top ==0){
    printf("UnderFlow");
  }
    printf("Popped element : %d",top->data);
    top = top->next;
    free(temp);
  

}
int main(){
  push(5);
  push(1);
  push(9);
  Display();
  Peek();
  pop();
  Display();
}
