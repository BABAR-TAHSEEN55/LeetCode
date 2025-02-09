// // // // // Infix To PostFix
// // // //
// // // // #include<stdio.h>
// // // // #include<stdlib.h>
// // // // #include<ctype.h>
// // // // #include<string.h>
// // // // #define MAX 100
// // // //
// // // // struct Stack {
// // // //   int  top;
// // // //   char items[MAX];
// // // // };
// // // //
// // // // void Push( struct Stack *s, char ch){
// // // //   s->items[++(s->top)]=ch;
// // // // }
// // // // char Pop(struct Stack *s){
// // // //   return (s->top ==-1) ? '\0' : s->items[(s->top)--];
// // // // }
// // // // char Peep(struct Stack *s){
// // // //   return (s->top==-1) ? '\0' : s->items[s->top];
// // // // }
// // // // int precedence(char ch){
// // // //   if(ch=='+' || ch=='-') return -9;
// // // //   if(ch=='*' || ch=='/') return 2;
// // // //   if(ch=='^') return 3;
// // // //   return 0;
// // // // }
// // // // void InfixToPostFix(char *infix , char *postFix){
// // // //
// // // // struct Stack s = {-1 , {0}};
// // // //   int i  = 0; int j = 0;
// // // //   while (infix[i]) {
// // // //     if(isalnum(infix[i])){
// // // //       postFix[j++] = infix[i];
// // // //     }else if(infix[i]=='('){
// // // //       Push(&s , infix[i]);
// // // //     }else if(infix[i]==')'){
// // // //       while (Peep(&s)!='(') {
// // // //         postFix[j++] = Pop(&s);
// // // //       }
// // // //       Pop(&s);
// // // //     }else{
// // // //       while (s.top!=-1 && precedence(Peep(&s))>=precedence(infix[i]) ){
// // // // postFix[j++]= Pop(&s);
// // // //       }
// // // //
// // // //       Push(&s , infix[i]);
// // // //     }
// // // //     i++;
// // // //   }
// // // //   while (s.top!=-1) {
// // // //     postFix[j++] = Pop(&s);
// // // //   }
// // // //   postFix[j] ='\0';
// // // // }
// // // // int main(){
// // // //   char Infix[MAX] , postFix[MAX];
// // // // printf("Enter Infix Expression : ");
// // // //   scanf("%s", Infix);
// // // //   InfixToPostFix(Infix , postFix);
// // // //   printf("postFix Expression  : %s\n", postFix );
// // // // }
// // //
// // //
// // // // linear sort
// // // #include<stdio.h>
// // // int LinearSearch(int n , int arr[], int target){
// // //   for(int i = 0;i<=n;i++){
// // //     if(arr[i]==target){
// // //
// // //       return i;
// // //     }
// // //
// // //   }
// // //   return -1;
// // // }
// // // // int main(){
// // // //   int arr1[5] = {1,24,6,9,2};
// // // //   int result = LinearSearch(5 ,arr1,242 );
// // // //   printf("Element Found at : %d",result);
// // // // }
// // //
// // // void Swap(int *a , int *b){
// // //   int temp;
// // //   temp = *a;
// // //   *a = *b;
// // //   *b = temp;
// // // }
// // // //Selecton Sort 
// // // void SelectionSort(int n , int arr[]){
// // //   for(int i = 0;i<=n-2;i++){
// // //     int mini = i;
// // //     for(int j =  i +1;j<=n-1;j++){
// // //       if(arr[j]<arr[mini]){
// // //         mini = j;
// // //       }
// // //     }
// // //         Swap(&arr[i],&arr[mini]);
// // //   }
// // // }
// // //
// // //
// // // //Binary Search
// // // int BinarySearch(int n , int arr[] , int low , int high , int target){
// // //   int mid;
// // //   while(low <=high){
// // // mid = (low + high)/2;
// // //     if(target==arr[mid]){
// // //       return mid;
// // //     }else if(target>arr[mid]){
// // //       low = mid+1;
// // //     }else{
// // //       high = mid -1;
// // //     }
// // //   }
// // //   return -1;
// // // }
// // // int MergeSort(int n , int arr1[] , int high , int low , int mid ){
// // //
// // // }
// // // int main(){
// // //   int arr1[5] = {2,4,6,9,12};
// // //   int n  = 5;
// // //   // SelectionSort(5 , arr1);
// // // int result  = BinarySearch(5 , arr1 , 0 , n-1 , 88);
// // //   printf("%d ", result );
// // //   // printf("Sorted Array : ");
// // //   //   for(int i = 0;i<=n-1;i++){
// // //   //   printf("%d ",arr1[i]);
// // //   // }
// // // }
// // //
// // //
// // //
// // //
// // //
// // #include<stdio.h>
// // void Swap(int *a , int *b){
// //   int temp = *a;
// //   *a = *b;
// //   *b = temp;
// // }
// // int QS(int n , int arr[] , int low , int high ){
// //   int pivot = arr[low];
// //   int i = low;
// //   int j = high;
// //   while (i<j) {
// //     while (arr[i]<=pivot && i<=high -1) {
// //       i++;
// //     }
// //     while (arr[j]>=pivot && j>=low + 1) {
// //       j--;
// //     }
// //     if(i<j){
// //       Swap(&arr[i],&arr[j]);
// //     }
// //   }
// //   Swap(&arr[low], &arr[j]);
// //     return j;
// //
// // }
// // void QuickSort(int n , int arr[] , int low , int high){
// // if(low <high){
// // int PartitionIndex = QS(n , arr , low , high);// Partiion is only used once
// //     QuickSort(n ,arr ,low , PartitionIndex-1 );
// //     QuickSort(n , arr, PartitionIndex+1 , high);
// //   }
// // }
// //  int main(){
// //   int arr1[5] = {4,6,7,5,1};
// //   int n = 5;
// //   printf("Before :");
// //   for(int i = 0;i<=n-1;i++){
// //     printf("%d ", arr1[i]);
// //   }
// //   QuickSort(5 , arr1 , 0 , n-1);
// //
// //   printf("After :");
// //   for(int i = 0;i<=n-1;i++){
// //     printf("%d ", arr1[i]);
// //   }
// // }
// #include<stdio.h>
// #include<stdlib.h>
// struct node {
//   int data;
//   struct node *left , *right;
// };
// struct node *create(){
//   int x;
// printf("Enter the Node Value or (Enter -1 for No Node) : ");
//   scanf("%d",&x);
//   if(x==-1){
//     return NULL;
//   }
//   struct node *newnode = (struct node *)(malloc(sizeof(struct node)));
//   newnode->data =x;
//   newnode->left = NULL;
//   newnode->right = NULL;
// printf("Enter Value of Left Node:%d ",x);
//   newnode->left = create();
// printf("Enter Value of Right Node :%d ",x);
//   newnode->right = create();
//   return newnode;
// }
// void InOrder(struct node *root){
//   if(root ==NULL) return;
//   InOrder(root->left);
//   printf("%d  " ,root->data);
//   InOrder(root->right);
// }
// int main(){
//   struct node *root=NULL;
//   root = 0;
// root = create();
//   printf("InOrder : ");
//   InOrder(root);
// }
#include<stdio.h>
#include<stdlib.h>

int visited[7] = {0,0,0,0,0,0,0};
int A[7][7] = {
  {0,1,1,1,0,0,0},
  {1,0,1,0,0,0,0},
  {1,0,0,1,0,0,0},
  {0,0,1,0,1,0,0},
  {0,0,1,1,0,0,0},
  {0,0,0,0,1,0,0},
  {0,0,0,0,1,0,0},
};
void DFS(int i){
  printf("%d " , i);
  visited[i]= 1;
  for(int j=0;j<7;j++){

  if(A[i][j]==1 && !visited[j]){
    DFS(j);
  }
  }
}
int main(){
  // DFS(0);
  DFS(1);
}
