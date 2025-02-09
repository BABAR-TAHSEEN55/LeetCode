#include<stdio.h>
void Swap(int *a , int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
int QS(int n , int arr[], int low , int high){
  int pivot = arr[low] ;
  int i = low;
  int j = high;
  while(i<j){
    while (arr[i]<=pivot && i<=high-1) {
      i++;
    }
    while (arr[j]>=pivot && j >=low+1) {
      j--;
    }
    if(i<j){
      Swap(&arr[i],&arr[j]);
    }
  }

Swap(&arr[low],&arr[j]);
  return j;
}
void QuickSort(int n , int arr[],int low , int high){
  if(low <= high){
    int PartitionIndex = QS(n , arr, low , high);
    QS(n , arr , low , PartitionIndex-1);
    QS(n , arr , PartitionIndex+1 , high);
  }
}
int main(){
    int arr1[5] = {4,7,1,5,9};
    int n = 5;
  printf("Before : ");
    for(int i = 0;i<n;i++){
      printf(" %d",arr1[i]);
    }
    QuickSort(5 , arr1 , 0 , n-1);
    
  printf("After : \n");
    for(int i = 0;i<n;i++){
      printf(" %d",arr1[i]);
    }
  }
