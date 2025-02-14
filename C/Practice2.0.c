// #include<stdio.h>
//
// void Swap(int *a , int *b){
//   int temp = *a;
//   *a = *b;
//   *b = temp;
// }
// void SelectionSort(int arr[], int n){
//   for(int i =0;i<n-1;i++){
//     int mini = i;
//     for(int j = i+1;j<n;j++){
//       if(arr[mini]>arr[j]){
//         mini = j;
//       }
//     }
//
//         Swap(&arr[i],&arr[mini]);
//
//   }
// }
//
// int QS(int arr[] , int low , int high){
//   int pivot = arr[low];
//   int i = low;
//   int j = high;
//   while (i<j) {
//     while (pivot>=arr[i]&&i<=high-1) {
//       i++;
//     }
//     while (pivot<=arr[j] && j >= low+1) {
//       j--;
//     }
//     if(i<j){
//       Swap(&arr[i], &arr[j]);
//     }
//
//   Swap(&arr[low], &arr[j]);
//   return j;
//   }
// }
// void QuickSort(int arr[] , int low , int high){
//   if(low<high){ 
//   int partitionIndex = QS(arr, low , high);
//   QuickSort(arr , low , partitionIndex -1);
//   QuickSort(arr , partitionIndex+1 , high);
// }
// }
//
// int LinearSearch(int arr[] ,int n, int target){
//   for(int i = 0;i<=n;i++){
//     if(arr[i]==target){
//
//       return i;
//
//     }
//   }
// return -1;
//
// }
// int main(){
//   int arr1[5] = {2,5,3,31,12};
//   // SelectionSort(arr1 , 5);
// int n = 5;
//   // QuickSort(arr1 , 0 , n-1);
// //  int result = LinearSearch(arr1, n , 31);
// // if(result!=-1){
// //     printf("Element Found at %d" , result);
// //   }else{
// //     printf("element not Foudn");
// //   }
//
//   // printf("After Sorting : ");
//   for(int i = 0;i<5;i++){
//     printf("%d ",arr1[i]);
//   }
//
// }



// #include<stdio.h>
// #include<stdlib.h>
// #define N 10
// int top = -1;
// int stacks[N];
//
// void Push(int x){
//   if(top==N-1){
//     printf("Stack is Full\n");
//     return;
//   }
//   top++;
//   stacks[top]=x;
// }
// void Peek(){
//   if(top==-1){
//     printf("Stack is Empty\n");
//
//     return;
//   }
//   printf("Top Element at the Stack : %d\n",stacks[top]);
// }
// void Pop(){
//   if(top==-1){
//     printf("Stack Is Empty\n");
//
//     return;
//   }
//   int item = stacks[top];
//   top--;
//   printf("Popped Element : %d\n",item);
// }
// void Display(){
//   printf("Elemetns in the Stacks are : ");
//   for(int i = top;i>=0;i--){
//
//     printf(" %d",stacks[i]);
//   }
// }
// int main(){
//   Push(5);
//   Push(9);
//   Push(88);
//   Push(99);
//   Push(987);
//   Push(767);
//   Peek();
//   Pop();
//   Peek();
//   Display();
// }
// #include<stdio.h>
// #include<stdlib.h>
// #define N 10
// struct Stack{
//   char data;
//   struct Stack *link;
// };
// struct Stack *top = NULL;
//
// void Push(char x){
//   struct Stack *newnode = (struct Stack *)(malloc(sizeof(struct Stack)));
//   if(newnode==NULL){
//     printf("Memory Allocation Failed \n");
//     return;
//   }
//   newnode->data = x;
//   newnode->link = top;
//   top = newnode;
// }
// void Pop(){
//   struct Stack *temp;
//   temp = top;
//   printf("Popped Element : %c\n",top->data);
//   top=top->link;
//   free(temp);
// }
// void Peek(){
//   if(top==NULL){
//     printf("Stack is Empty\n");
//     return;
//   }
//   printf("Top Element in the Stack : %c\n", top->data);
// }
// void Display(){
//   struct Stack *temp;
//   temp = top;
//   while (temp!=NULL) {
//     printf("Elements in the Stack : %c\n", temp->data);
//     temp = temp->link;
//   }
// }
// int main(){
//   Push('c');
//   Push('d');
//   Push('a');
//   Push(20);
//   Push(10);
//   Push(60);
//   Push(70);
//   Push(80);
//   Push(90);
//   Pop();
//   Peek();
//   Display();
// }

#include<stdio.h>
#include<stdlib.h>
#define N 10
int front = -1;
int rear = -1;
int Queue[N];
void Enqueue(int x){
  if(rear ==N-1){
    printf("QUeue is Full\n");
      return;
  }
  if(front ==-1){

  front++;
  }
  rear ++;
  Queue[rear] = x;
}
void Pop(){
  if(front ==-1){
    printf("Queue is Empty\n");
    return;
  }
  int item = Queue[front];
  front++;
printf("Dequeue element : %d", item);
}
void Peek(){

  if(front ==-1){
    printf("Queue is Empty\n");
    return;
  }

printf("Top element in the Queue : %d \n" ,Queue[front]);
}
void Display(){
  
  if(front ==-1){
    printf("Queue is Empty\n");
    return;
  }
  printf("element in : ");
for(int i = rear;i>=0;i--){
printf("%d\n",Queue[i]);
  }
}
int main(){
  Enqueue(5);
  Enqueue(3);
  Enqueue(4);
  Enqueue(6);
  Enqueue(89);
  Pop();
  Peek();
  Display();
}
