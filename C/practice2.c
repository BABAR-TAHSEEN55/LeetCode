#include <stdio.h>
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
int main(){
  int arr1[5] = {2,4,6,8,20};
  int result = BinarySearch(5 , arr1 , 20);
  printf("%d",result);
}
void Enqueue(int x){
  struct Queue *newnode = (struct Queue *)(malloc(sizeof(struct Queue)));
  if(rear ==N-1){
    printf("Queue is Full");
    return;
  }
  newnode->data = x;
  newnode->link = 0;
  if(front ==rear ==0){
    front =rear = newnode;
  }
  rear->link = newnode;
  rear = newnode;
}
