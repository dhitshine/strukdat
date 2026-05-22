/*
 Source: Slide 
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val, height;
  Node *left, *right;
};

Node *create_node(int val) {
  Node *node = new Node;
  node->left = nullptr;
  node->right = nullptr;
  node->val = val;
  node->height = 1;
  return node;
}

int height(Node *node) {
  if(node == nullptr) {
    return 0;
  }
  return node->height;
}

Node* insert(Node *root, int val) {
  if(root == nullptr) {
    return create_node(val);
  }
  if(val < root->val) {
    root->left = insert(root->left, val);
  }else {
    root->right = insert(root->right, val);
  }
  root->height = 1 + max(height(root->left), height(root->right));
  return root;
}

Node* search(Node *root, int val) {
  if(root == nullptr || val == root->val) {
    return root;
  }
  if(val < root->val) {
    return search(root->left, val);
  }else {
    return search(root->right, val);
  }
}

Node* findMin(Node *node) {
  Node *curr = node;
  while(curr->left != nullptr) {
    curr = curr->left;
  }
  return curr;
}

Node* remove(Node *node, int val) {
if(node == nullptr) {
    return nullptr;
  }
  if(val < node->val) {
    node->left = remove(node->left, val);
  }else if(val > node->val) {
    node->right = remove(node->right, val);
  }else {   // val == node.val
    if(node->left == nullptr) {
      Node *temp = node->right;
      delete node;
      return temp;
    }
    if(node->right == nullptr) {
      Node *temp = node->left;
      delete node;
      return temp;
    }
    Node *succesor = findMin(node->right);
    node->val = succesor->val;
    node->right = remove(node->right, succesor->val);
  }
  node->height = 1 + max(height(node->left), height(node->right));
  return node;
}

int main() {
  Node *root = nullptr;
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 5);
  root = insert(root, 9);
  Node *node_1 = search(root, 1);
  int height_of_1 = height(node_1);
  cout << height_of_1 << endl;

  Node *node_3 = search(root, 3);
  int height_of_3 = height(node_3);
  cout << height_of_3;
  return 0;
}
