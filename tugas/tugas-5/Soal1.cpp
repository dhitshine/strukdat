/*
 Source: Kalicharan, Advanced Topics in C, p.156 no.14
 */

#include <iostream>
using namespace std;

struct Node {
  Node *next;
  int val;
};

Node* create_node(int val) {
  Node *node = new Node;
  if(node == nullptr) {
    return nullptr;
  }
  node->next = nullptr;
  node->val = val;
  return node;
}

bool sorted(Node *node) {
  if(node == nullptr || node->next == nullptr) {
    return true;
  }
  if(node->val > node->next->val) {
    return false;
  }
  return sorted(node->next);
}

int main() {
  Node *head = create_node(2);
  head->next = create_node(20);
  head->next->next = create_node(30);
  head->next->next->next = create_node(45);
  if(sorted(head)) {
    cout << "List is sorted in ascending order." << endl;
  }else {
    cout << "List is not sorted in ascending order." << endl;
  }
  return 0;
}
