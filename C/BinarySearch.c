#include<stdio.h>

int BinarySearch(int n , int arr[], int target){
int low = 0;
  int high = n-1;
  while(low<=high){
  int mid = (low + high)/2;
if(arr[mid] ==target) {
return mid;
    }else if(target>arr[mid]){
      low = mid +1;
    }else{
      high = mid-1;
    }
  }
  return -1;
}
int BinarySearchRecursive(int n ,int high , int low , int target , int arr[]){
  if(low>high){
    return -1;
  }

int   mid = (low+high)/2;
  if(arr[mid]==target){
    return mid;
  }else if(target > arr[mid]){
    return BinarySearchRecursive(n,high , mid+1,target,arr);
  }else{
    return BinarySearchRecursive(n,mid-1 , low,target,arr);
  }
}
int main(){
int array[5] = {3,4,5,9,10};
//  int result =  BinarySearch(5,array,9);
// printf("Result : %d",result);
  int n = 5;
 int result =  BinarySearchRecursive(n, n-1 , 0 , 10 , array);
  
printf("Result : %d",result);
}
