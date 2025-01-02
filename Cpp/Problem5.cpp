#include<bits/stdc++.h>
using namespace  std; 


void naturalnumbers(int n) {
  for(int i =1;i<=10;i++){
cout<<i<<endl;
  }
}

void naturalnumberssum(int n) {
  int sum = 0;
  for(int i = 0;i<=n;i++){

sum+=i;
  }
  cout<<sum;
}

bool perfectnumber(int n ) {
  int sum = 1;
for(int i = 2;i*i<=n;i++){
    if(n%i==0){
      sum+=i;
 
    if(n/i!=i){
      sum+=(n/i);
    }
//If you dont nest it then it'll run independently if even if i is not the divisior
    }
  }
  return(sum==n)?true:false;

}


// void AllNum(int start , int end ){
//   for(int i = start;i<=end;i++){
//     if(perfectnumber(i)){
//       cout<<"pn"<<endl;
//       cout<<i;
//     }
//   }
// }

void PrimeNumber(int n){
  int count =0;
  for(int i = 1;i*i<=n;i++){
    if(n%i==0){
        count++;
      if((n/i)!=i){
        count++;
      }
    }
  }
  count==2?cout<<"PM":cout<<"NPM";
}

// void AllNum(int start , int end ){
//   for(int i = start;i<=end;i++){
//     if(PrimeNumber(i)){
//       cout<<"pn"<<endl;
//       cout<<i;
//     }
//   }
// }

int main(){
  // naturalnumbers(10);
  // naturalnumberssum(10);
    // perfectnumber(28);
  // AllNum(6,500);
  PrimeNumber(9);
}
