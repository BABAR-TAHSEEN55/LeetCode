#include<stdio.h>

int BinarySearch(int n , int arr[] ,int target){
  int low = 0;
  int high = n-1;
  while (low<=high) {
    int mid = (low + high)/2;
    if(arr[mid ]==target){
      return mid;
    }else if(arr[mid]<target){
low = mid+1;
    }else {
      high = mid -1;
    }
  }
  return -1;
}

int main(){
  int arr1[5] = {2,4,5,6,8};
  int n = 5;

 int result = BinarySearch(5,arr1,5);
  printf("%d ",result);
  
}
