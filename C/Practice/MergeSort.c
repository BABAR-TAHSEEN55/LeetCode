#include<stdio.h>
#include<stdlib.h>
#define N 20
void Merge(int arr[], int low , int mid , int high){
  int temp[N];
  int left = low;
  int right = mid +1;
  int k = low;
  while (left<=mid && right<=high) {
    if(arr[left]<=arr[right]){
      temp[k++] = arr[left++];
    }else{
      temp[k++] = arr[right++];
    }
  }
  while (left <=low) {
    temp[k++]  = arr[left++];
  }
  while (right <=high) {
    temp[k++]  = arr[right++];
  }
  for(int i  = low ;i<high;i++){
    arr[i] = temp[i];
  }
}
void MergeSort(int arr[], int low , int high){
  if(low>=high){
    return;
  }
  int mid = (low + high)/2;
  MergeSort(arr , low , mid);
  MergeSort(arr , mid +1 , high);
  Merge(arr , low , mid , high);
}
