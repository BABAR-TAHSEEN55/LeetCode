#include<bits/stdc++.h>
using namespace  std;
  
void PyramidPattern(int n){
for(int i =0;i<=n;i++){
    for(int j = 0;j<n-i-1;j++){
      cout<<" ";
    }
    for(int j =0;j<2*i+1;j++){
      cout<<"*";
    }
    for(int j = 0;j<n-i-1;j++){
      cout<<" ";
    }
  cout<<endl;
  }

}


void ReversePatter(int n){
  for(int i =0;i<=n;i++){
    for(int j = 0;j<i;j++){
      cout<<" ";
    }
    for(int j = 0;j<2*n-2*i-1;j++){
    cout<<"*";
  }
    for(int j = 0;j<i;j++){
      cout<<" ";
    }

  cout<<endl;
  }
}
void FullPattern(int  n ){
  for(int i = 0;i<n;i++){
    for(int j = 0;j<=i;j++){
      cout<<"*";
    }
    cout<<endl;
  }

  for(int i = 0;i<n;i++){
    for(int j = 0;j<n-i-1;j++){
      cout<<"*";
    }
    cout<<endl;
  }
}

void TogglePattern(int n ){
  for(int i  = 0;i<n;i++){
    int start =(i%2==0)?1:0;
    for(int j = 0;j<=i;j++){
      cout<<start;
      start = 1-start;
    }
    cout<<endl;
  }
}
int main(){
  // PyramidPattern(5);
    // ReversePatter(5);
  FullPattern(5);
TogglePattern(5);
}
