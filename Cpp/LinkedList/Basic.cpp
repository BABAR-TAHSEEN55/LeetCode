
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *next;

public:
  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
  }

public:
  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};

Node *ConvertArrToLL(vector<int> &vr) {
  Node *head = new Node(vr[0]);
  Node *mover = head;
  for (int i = 1; i < vr.size(); i++) {
    Node *newNode = new Node(vr[i]);
    mover->next = newNode;
    mover = newNode;
  }
  return head;
}

int main() {
  vector<int> arr = {2, 8, 5, 6};
  // Node *y = new Node(arr[0], nullptr);
  // cout << y->data << endl;

  Node *head = ConvertArrToLL(arr);

  Node *temp = head;
  int number;
  cout << "Enter Number : ";
  cin >> number;

  while (temp) {

    if (number == temp->data) {
      cout << "Found";
      cout << temp->data;
      return 1;
    }
    temp = temp->next;
    // cout << temp->data << " ";
  }
  cout << "Not Found";
}
