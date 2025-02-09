#include <stdio.h>

void LinearSearch(int n , int arr[]){
  int element;
  printf("Enter Element Value");
  scanf("%d",&element);
  for(int i = 0;i<=n;i++){
    if(arr[i]==element){
      printf("element found at index : %d",i);
      break;
    }
  }

    printf("Element Not FOund ");
}
int main(){
  int arr[]= {1,2,3,4,5};
LinearSearch(5,arr);
}
