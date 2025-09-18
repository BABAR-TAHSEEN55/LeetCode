#include<bits/stdc++.h>
using namespace std;

void SetZero( int arr[], int n , int m ) {
for(int i =0;i<m:i++){
for ( int j =0;j<n:j++){
if(arr[i][j]==0){
MarkRowZero(i);
MarkColo
  umnZero(j);
}

void MarkRowZero(i){
  for (int j=0;j<m;j++){
    if(arr[i][j]!=0){
      arr[i][j]=-1;
    }
  }
}
// Check this part Once
void MarkColumnZero(j){
  for (int i=0;i<m;i++){
    if(arr[i][j]!=0){
      arr[i][j]=-1;
    }
  }
}
int main(){
SetZero(arr,4,3);
}
