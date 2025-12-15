#include <bits/stdc++.h>
#include <stack>

using namespace std;

int main() {
  stack<int> st;
  int data = 2;
  st.push(data);
  while (!st.empty()) {
    cout << st.top();
    st.pop();
  }
}
