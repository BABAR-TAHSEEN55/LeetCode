#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int  BinarySearch(int arr[] , int low , int high,int target){
  while(low <=high){
    int mid = (low + high)/2;
    if(arr[mid]==target){
      return mid;
    }else if(target > arr[mid]){
      low = mid + 1;
    }else {
      high = mid -1;
    }
  }
  return -1;
}
int main(){
int n =5;
  int arr[5] = {2,4,5,6,7};
  int result = BinarySearch(arr,0,n-1,6);
  cout<<result;
}
