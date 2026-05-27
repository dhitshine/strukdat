#include <iostream>
using namespace std;

struct Node {
  int val;
  Node *left, *right;
};


Node* createNode(int val) {
  Node *temp = new Node;
  temp->left = nullptr;
  temp->right = nullptr;
  temp->val = val;
  return temp;
}

int smallest_greater(Node *root, int val) {
  Node *curr = root;
  int ans = -1;
  while(curr != nullptr) {
    if(curr->val > val) {
      ans = curr->val;
      curr = curr->left;
    }else {
      curr = curr->right;
    }
  }
  return ans;
}
