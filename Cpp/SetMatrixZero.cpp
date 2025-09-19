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

void BetterSolution ( int arr[] , int m , int n ) {
 int col[m]={0};
   int Row[n]={0};
  
  for( int i =0 ;i<m;i++){
  for( int j=0;j<m;j++){
    if(arr[i][j]==0){
      Row[i]= 1;
      col[j]=2;
    }
  }
  }
  for( int i =0 ;i<m;i++){
  for( int j=0;j<m;j++){
    if(Row[i] ||col [j] ){
      arr[i][j]=0;
    }
  }
  }
}
