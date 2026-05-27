#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
  int val;
  Node *left, *right;
  int height;
};

Node* createNode(int val) {
  Node* temp = new Node;
  temp->val = val;
  temp->left = nullptr;
  temp->right = nullptr;
  temp->height = 1;
  return temp;
}

int getHeight(Node* n) {
  return n == nullptr ? 0 : n->height;
}

int getBalance(Node* n) {
  return n == nullptr ? 0 : getHeight(n->left) - getHeight(n->right);
}

Node* rightRotate(Node* y) {
  Node* x = y->left;
  Node* T2 = x->right;

  x->right = y;
  y->left = T2;
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  return x;
}

Node* leftRotate(Node* x) {
  Node* y = x->right;
  Node* T2 = y->left;

  y->left = x;
  x->right = T2;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

  return y;
}

Node* balanceTree(Node* root) {
  if(root == nullptr){
    return nullptr;
  }

  root->left = balanceTree(root->left);
  root->right = balanceTree(root->right);
  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

  int balance = getBalance(root);

  if(balance > 1 && getBalance(root->left) >= 0) {
    return rightRotate(root);
  }
  if(balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  if(balance < -1 && getBalance(root->right) <= 0) {
    return leftRotate(root);
  }
  if(balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}

void print_tree(Node* root, int space = 0, int height = 4) {
  if(root == nullptr){
    return;
  }

  space += height;

  print_tree(root->right, space);
  cout << endl;
  for(int i = height; i < space; i++){
    cout << " ";
  }
  cout << root->val << endl;
  print_tree(root->left, space);
}

int main() {
  Node* root = createNode(10);
  root->right = createNode(20);
  root->right->right = createNode(30);
  root->right->right->right = createNode(40);

  cout << "Binary Tree" << endl;
  print_tree(root);

  root = balanceTree(root);

  cout << "AVL Balance" << endl;
  print_tree(root);

  return 0;
}
