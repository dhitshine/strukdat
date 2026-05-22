#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *next, *prev;
};

Node* createNode(int val) {
  Node *temp = new Node;
  temp->next = nullptr;
  temp->prev = nullptr;
  temp->val = val;
  return temp;
}

Node* change(Node *node) {
  if(node == nullptr) {
    return nullptr;
  }
  Node *temp = node->prev;
  node->prev = node->next;
  node->next = temp;
  if(node->prev == nullptr) {
    return node;
  }
  return change(node->prev);
}

int main() {
  Node *head = createNode(10);
  head->next = createNode(12);
  head->next->prev = head;
  head->next->next = createNode(5);
  head->next->next->prev = head->next;
  head->next->next->next = createNode(20);
  head->next->next->next->prev = head->next->next;
  cout << "Before:" << endl;
  Node *temp = head;
  while(temp != nullptr) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl << "After:" << endl;
  temp = change(head);
  while(temp != nullptr) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  delete head;
  return 0;
}
