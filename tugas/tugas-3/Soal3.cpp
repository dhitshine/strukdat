#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *next;
};

Node* createNode(int val) {
  Node *temp = new Node;
  temp->next = nullptr;
  temp->val = val;
  return temp;
}

Node *add(Node *a, Node *b) {
  Node *dummy = createNode(0);
  Node *curr = dummy;
  int carry = 0;
  while(a != nullptr || b != nullptr || carry > 0) {
    int sum = carry;
    if(a != nullptr) {
      sum += a->val;
      a = a->next;
    }
    if(b != nullptr) {
      sum += b->val;
      b = b->next;
    }
    carry = sum / 10;
    curr->next = createNode(sum % 10);
    curr = curr->next;
  }
  Node *res = dummy->next;
  delete dummy;
  return res;
}

int main() {
  Node *a = createNode(2);
  a->next = createNode(5);
  a->next->next = createNode(1);
  Node *b = createNode(8);
  b->next = createNode(4);
  b->next->next = createNode(1);
  Node *res = add(a, b);      // 152 + 148 = 300
  Node *temp = res;
  while(temp != nullptr) {
    cout << temp->val;
    temp = temp->next;
  }
  delete a;
  delete b;
  return 0;
}
