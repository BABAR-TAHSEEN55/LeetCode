// #include<stdio.h>
// #include<stdlib.h>
// // #include<ctype.h>
// // #include<string.h>
// // #define MAX 100
// // struct Stack {
// //   int top ;
// // char items[MAX];
// // };
// // void Push(struct Stack *s, char ch){
// //   s->items[++(s->top)] = ch;
// // }
// //
// // char Pop(struct Stack *s){
// // return (s->top==-1) ? '\0'  : s->items[(s->top)--];
// // }
// // char Peep(struct Stack *s){
// //   return (s->top==-1) ? '\0' : s->items[s->top];
// // }
// // int Precedance(char ch){
// // if(ch=='+' || ch=='-') return 1;
// // if(ch=='*' || ch=='/') return 2;
// //   if(ch=='^') return 3;
// //   return 0;
// // }
// // void InfixToPostFix(char *infix , char *postfix){
// // struct Stack s = {-1 , {0}};
// //   int i = 0 , j = 0;
// //   while (infix[i]) {
// //     if(isalnum(infix[i])){
// //       postfix[j++] = infix[i];
// //     }else  if(infix[i]=='('){
// //       Push(&s ,infix[i]);
// //     }else if(infix[i]==')') {
// //       while (s.top!=-1 && Peep(&s)!='(') {
// //         postfix[j++] = Pop(&s);
// //       }
// //       Pop(&s);
// //     }else{
// //       while (s.top!=-1 && Precedance(Peep(&s))>=Precedance(infix[i])) {
// //         postfix[j++] = Pop(&s);
// //       }
// //       Push(&s , infix[i]);
// //     }
// //         i++;
// //
// //   }
// //   while (s.top!=-1) {
// //   postfix[j++] = Pop(&s);
// //   }
// //     postfix[j]= '\0';
// // }
// // int main(){
// //   char infix[MAX] ,  postfix[MAX];
// //   printf("Enter Infix Expresison : ");
// //   scanf("%s", infix);
// //   InfixToPostFix(infix, postfix);
// //
// //   printf("Enter Postfix Expresison : %s", postfix);
// //
// // }
// //
// #define N 10
// void Merge(int arr[] , int low , int mid , int high){
//   int temp[N];
//   int left = low;
//   int right = mid+1;
//   int k = low;
//   while(left<=mid && right <=high){
//   if(arr[left]<=arr[right]) {
// temp[k++] = arr[left++];
//   }else{
//     temp[k++]= arr[right++];
//   }
//
//   }
//
// while (left<=mid){
// temp[k++] = arr[left++];
// }
// while (right<=high){
// temp[k++] = arr[right++];
// }
// for(int i =low;i<=high;i++){
//   arr[i] = temp[i];
// }
// }
// void MergeSort( int arr[] , int low , int high){
//   if(low>=high){
//     return;
//   }
//   int mid = (low + high)/2;
//   MergeSort(arr, low , mid);
//   MergeSort(arr, mid+1 , high);
//   Merge(arr, low , mid , high);
// }
// int main(){
//   int arr1[5] = {4,5,9,1,2};
//   int n =5;
//   printf("Before MergeSOrt : ");
//   for(int i =0;i<=n;i++){
//     printf("%d",arr1[i]);
//   }
//   MergeSort(arr1,0,n-1);
//
//   printf("after MergeSOrt : ");
//   for(int i =0;i<=n;i++){
//     printf("%d",arr1[i]);
//   }
// }
void Swap(int *a , int *b){
  int temp  = *a;
  *a = *b;
  *b = temp;
}
void QuickSort(int n , int arr[], int low , int high){
  if(low>=high){
    return 0;
  }
  int mid = (low + high)/2;
  int PartitionIndex = QS(arr , low , mid , high);
  QuickSort(n ,arr , low ,mid);
  QuickSort(n , arr , mid + 1 , high);
}
void QS(int arr[], int low ,int mid , int high){
  int pivot  = arr[low];
  int i = low ;
  int j = high;
  while (pivot>=arr[i]&& i<=high-1) {
  i++;
  }
  while (pivot<=arr[j] && j >=low + 1) {
    j++;
  }
  if(i<j){
    Swap(&arr[i],&arr[j]);
  }
}
