#include<bits/stdc++.h>
using namespace std;
void Alphabets(int n){
for(int i =0;i<=n;i++){
for(char c = 'A';c<='A'+n-i;c++){//when you do n-i simply it would result in nothing cause i am comapring a char with int as char c ASCII is 65 , and the condition would be 65<=5 which is false that is why not working 
      cout<<c;
    }
    cout<<endl;
  }
}
int main(){
Alphabets(5);
}
