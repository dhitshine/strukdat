/*
 Source: Kalicharan, Advanced Topics in C, p.101 no.12
 */

#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *next, *prev;
};

Node* createNode(int val) {
  Node *node = new Node;
  if(node == nullptr) {
    return nullptr;
  }
  node->val = val;
  node->next = nullptr;
  node->prev = nullptr;
  return node;
}

Node* circular(int n) {
  Node *head, *temp, *tail;
  head = tail = nullptr;
  for(int i = 1; i <= n; i++) {
    temp = createNode(i);
    if(head == nullptr) {
      head = tail = temp;
    }else {
      tail->next = temp;
      tail->next->prev = tail;
      tail = temp;
    }
  }
  tail->next = head;
  head->prev = tail;
  return head;
}

int remaining(int n, int m) {
  Node *head = circular(n);
  Node *curr = head;
  while(curr->next != curr) {
    if(m > 0) {
      for(int i = 1; i < m; i++){
        curr = curr->next;
      }
    }else {
      for(int i = 1; i < -m; i++){
        curr = curr->prev;
      }
    }
    Node *del = curr;
    curr = curr->next;
    del->prev->next = del->next;
    del->next->prev = del->prev;
    delete del;
  }
  int ans = curr->val;
  delete curr;
  return ans;
}

int main() {
  int n, m;
  cout << "Enter number of children: ";
  cin >> n;
  cout << "Enter number of words [-4, 0) or (0, 4] : ";
  cin >> m;
  if(m == 0) {
    cout << "m = 0 is not valid.";
    return 1;
  }
  int win = remaining(n, m);
  cout << "Last remaining: " << win << endl;
  return 0;
}

