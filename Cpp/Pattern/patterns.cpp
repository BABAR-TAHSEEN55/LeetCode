
#include <bits/stdc++.h>
using namespace std;
void Pattern1(int n) {
  for (int i = n; i > 0; i--) {
    for (int j = i; j < n; j++) {
      cout << "*";
    }
    cout << endl;
    ;
  }
}

int main() { Pattern1(5); }
