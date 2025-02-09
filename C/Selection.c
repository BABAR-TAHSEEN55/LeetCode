#include<stdio.h>
void Swap(int *a , int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
int SelectionSort(int n , int arr[]){
  for(int i = 0;i<n-2;i++){
    int mini = i;
    for(int j = i+1;j<n-1;j++){
      if(arr[mini]>arr[j]){
        mini = j;
      }
    }
      Swap(&arr[mini], &arr[i]);
  }
}
int main(){
  int arr1[5] = {8,2,1,5,9};
  int n = 5;
  printf("Before Sorting :");
  for(int i =0;i<=n;i++){
    printf("%d ",arr1[i]);
  }
SelectionSort(5 , arr1);
  printf("After Sorting :");
  for(int i =0;i<=n;i++){
    printf("%d ",arr1[i]);
  }
}
