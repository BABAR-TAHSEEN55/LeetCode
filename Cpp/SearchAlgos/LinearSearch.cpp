#include<iostream>
using namespace std;


int LinearSearch(int arr[] , int n, int target){
  for(int i = 0;i<=n;i++){
    if(arr[i]==target){
      return i;
    }
  }
  return -1;
}


int main(){
  int n =5;

int arr[n]  = {1,2,3,4,5};

int result = LinearSearch(arr,5,4);
  cout<<result;
}
  
