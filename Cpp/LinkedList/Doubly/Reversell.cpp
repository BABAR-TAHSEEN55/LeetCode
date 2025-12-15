

#include <bits/stdc++.h>
#include <new>
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
  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};

Node *Convert2Dll(vector<int> &vr) {
  Node *head = new Node(vr[0]);
  Node *prev = head;
  for (int i = 1; i < vr.size(); i++) {
    Node *newNode = new Node(vr[i], nullptr);
    prev->next = newNode;
    prev = newNode;
  }
  return head;
}

void print(Node *head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
}
Node *ReversLL(Node *head) {
  Node *DummyHead = NULL;
  Node *temp = head;
  while (head != NULL) {
    temp = temp->next;
    head->next = DummyHead;
    DummyHead = head;
    head = temp;
  }

  return DummyHead;
}
int main() {
  vector<int> arr = {1, 2, 4, 56, 8};
  Node *head = Convert2Dll(arr);
  head = ReversLL(head);
  print(head);
}
