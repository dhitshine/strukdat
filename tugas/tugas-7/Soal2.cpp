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

Node *preorder(Node *root, int val) {
  if(root == nullptr || root->val == val) {
    return root;
  }
  Node *search_left = preorder(root->left, val);
  if(search_left != nullptr) {
    return search_left;
  }
  return preorder(root->right, val);
}

Node *inorder(Node *root, int val) {
  if(root == nullptr) {
    return nullptr;
  }
  Node *search_left = inorder(root->left, val);
  if(search_left != nullptr) {
    return search_left;
  }
  if(root->val == val) {
    return root;
  }
  return inorder(root->right, val);
}

Node *postorder(Node *root, int val) {
  if(root == nullptr) {
    return nullptr;
  }
  Node *search_left = postorder(root->left, val);
  if(search_left != nullptr) {
    return search_left;
  }
  Node *search_right = postorder(root->right, val);
  if(search_right != nullptr) {
    return search_right;
  }
  if(root->val == val) {
    return root;
  }
  return nullptr;
}
