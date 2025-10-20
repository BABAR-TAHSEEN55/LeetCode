#include <bits/stdc++.h>
#include <new>
#include <vector>

using namespace std;
class Node {
public:
  int data;
  Node *next;
  Node *back;

public:
  Node(int data1, Node *next1, Node *back1) {
    data = data1;
    next = next1;
    back = back1;
  }
  Node(int data1) {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

Node *Convert2Dll(vector<int> &vr) {
  Node *head = new Node(vr[0]);
  Node *prev = head;
  for (int i = 1; i < vr.size(); i++) {
    Node *newNode = new Node(vr[i], nullptr, prev);
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
Node *DeleteHead(Node *head) {
  Node *prev = head;
  head = head->next;
  head->back = nullptr;
  prev->next = nullptr;
  delete prev;
  return head;
}
Node *DeleteTail(Node *head) {
  if (head == NULL || head->next == NULL) {
    return NULL;
  }
  Node *tail = head;
  while (tail->next != NULL) {
    tail = tail->next;
  }
  Node *NewTail = tail->back;
  NewTail->next = nullptr;
  tail->back = nullptr;
  delete tail;
  return head;
}

Node *DeleteKthElement(Node *head, int k) {
  if (head == NULL) {
    return NULL;
  }
  int cnt = 0;
  Node *KNode = head;
  while (KNode != NULL) {
    cnt++;
    if (cnt == k) {
      break;
    }
    KNode = KNode->next;
  }
  Node *prev = KNode->back;
  Node *front = KNode->next;
  if (front == NULL && prev == NULL) {
    return NULL;
  } else if (prev == NULL) {
    return DeleteHead(KNode);
  } else if (front == NULL) {
    return DeleteTail(KNode);
  }
  prev->next = front;
  front->back = prev;
  KNode->next = nullptr;
  KNode->back = nullptr;
  delete KNode;
  return head;
}

Node *DeleteNode(Node *temp) {
  // Reminder : Head won't be the node that is to be deleted
  return temp;
}

Node *InsertNewNode(Node *head, int val) {
  Node *NewHead = new Node(val);
  if (head == NULL) {
    NewHead->next = nullptr;
    NewHead->back = nullptr;
    return NewHead;
  }
  NewHead->data = val;
  NewHead->next = head;
  head->back = NewHead;
  return NewHead;
}

Node *InsertBeforetail(Node *head, int val) {
  Node *tail = head;
  while (tail->next != NULL) {
    tail = tail->next;
  }
  Node *prev = tail->back;
  Node *NewNode = new Node(val, tail, prev);
  prev->next = NewNode;
  tail->back = NewNode;
  return head; // Returns the head as it is unchanged
}
Node *InsertBeforeKthElement(Node *head, int val, int elem) {
  Node *temp = head;
  while (temp->next != NULL) {
    if (temp->data == val) {
      break;
    }

    temp = temp->next;
  }
  Node *prev = temp->next;
  Node *front = temp->back;
  Node *newNode = new Node(elem, front, prev);
  prev->next = newNode;
  front->back = newNode;
  return head;
}
int main() {
  vector<int> arr = {1, 2, 3, 34, 56};
  Node *head = new Node(arr[0]);
  head = Convert2Dll(arr);
  // head = DeleteHead(head);
  // head = DeleteTail(head);
  // int count;
  // cout << "Enter Count  ";
  // cin >> count;
  // head = DeleteKthElement(head, count)  head = InsertNewNode(head, 2299);
  // head = InsertBeforetail(head, 8);
  head = InsertBeforeKthElement(head, 34, 33);
  print(head);
}
