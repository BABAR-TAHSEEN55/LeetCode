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

bool PrimeNumber(int n){
  int count =0;
  for(int i = 1;i*i<=n;i++){
    if(n%i==0){
        count++;
      if((n/i)!=i){
        count++;
      }
    }
  }

  return (count==2)?true :false;
}

// void AllNum(int start , int end ){
// int previousPrime = -1;
//   for(int i = start;i<=end;i++){
//     if(PrimeNumber(i)){
//       if(previousPrime!=-1)
//       cout<<i;
//     }
//     previousPrime=i;
//   }
// }
bool Prime(int n){
  // if(n<1) return ;
  for(int i =2;i*i<=n;i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}
void Run(int n){
  for(int i = n-1;i>=2;i--){
    if(Prime(i)){
      cout<<i;
      return;
    }
  }
}


int Gcd(int a , int b){
  while(a > 0 && b>0){
    if(a>b){
      a%=b;
    }else{
      b%=a;
    }

  }
return (a==0)? b : a;

}



// float sum = 0;
//   while(n>0){
//
//     float digit = n%10;
//     n = n/10;
//     sum = sum + digit;
//   }
//   return (float)sum;
// }
//


 void SquarePattern(int n){
  for(int i =0;i<=n;i++){
    for(int j = 0;j<n;j++){
      cout<<i;
    }
    cout<<endl;
  }
}
int Cube(int n){
  return n*n*n;
}
void PrintCube(int start , int end){
  for(int i =start ;i<=end;i++){
    cout<<Cube(i)<<endl;
  }
}

void StartPattern2(int n){
  for(int i =0;i<=n;i++){
    for(int j = 0;j<=i;j++){
      cout<<"*";
    }
    cout<<endl;
  }
}

void NumberPatern(int n){
  for(int i =0;i<=n;i++){
    for(int j = 0;j<=i;j++){
      cout<<j;
    }
    cout<<endl;
  }
}
void CrazyPattern(int n){

int spaces = 2*(n-1);
for(int i =1;i<=n;i++){
    for(int j = 1;j<=i;j++){
      cout<<j;
    }
for(int j=1;j<=spaces;j++){
      cout<<" ";
    }
    for(int j =i;j>=1;j--){
      cout<<j;
    }

    spaces-=2;
    cout<<endl;
  }
}
int main(){
  // naturalnumbers(10);
  // naturalnumberssum(10);
    // perfectnumber(28);
  // AllNum(6,500);
  // PrimeNumber(9);
  // AllNum(2,10);
// PrimePrev(5);
  // Run(10);
// int result =Gcd(10,5);
// SquarePattern(5);
// PrintCube(1,5);
// float result = SumOfDigits(123);
// cout<<result;
  // StartPattern2(5)
  // NumberPatern(5);
  CrazyPattern(5);
}
