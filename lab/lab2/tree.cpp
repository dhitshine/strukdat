#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val, size;
  Node *left, *right;
};

struct Tree { // BST
private:
  Node *root;
  int size(Node *node) {
    if(node == nullptr) {
      return 0;
    }
    return node->size;
  }
  Node* create_node(int val) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->left = nullptr;
    node->right = nullptr;
    node->val = val;
    node->size = 1;
    return node;
  }
  Node* _insert(Node *node, int val) {
    Node *temp = create_node(val);
    if(node == nullptr) {
      return temp;
    }
    if(val < node->val) {
      node->left = _insert(node->left, val);
    }else {
      node->right = _insert(node->right, val);
    }
    node->size = 1 + size(node->left) + size(node->right);
    return node;
  }
  int _order(Node *node, int val) {
    if(node == nullptr) {
      return 0;
    }
    if(val == node->val) {
      return size(node->left) + 1;
    }
    if(val < node->val) {
      return _order(node->left, val);
    }else {
      return _order(node->right, val) + size(node->left) + 1;
    }
  } 
  Node* _search(Node *node, Node *par, int val) {
    if(node == nullptr) {
      return node;
    }
    if(val == node->val) {
      return par;
    }
    if(val < node->val) {
      return _search(node->left, node, val);
    } else {
      return _search(node->right, node, val);
    }
  }
  Node* findMin(Node *node) {
    while(node->left != nullptr) {
      node = node->left;
    }
    return node;
  }
  Node* _delete(Node *node, int val) {
    if(node == nullptr) {
      return nullptr;
    }
    if(val < node->val) {
      node->left = _delete(node->left, val);
    }else if(val > node->val) {
      node->right = _delete(node->right, val);
    }else {   // val == node.val
      if(node->left == nullptr) {
        Node *temp = node->right;
        free(node);
        return temp;
      }
      if(node->right) {
        Node *temp = node->left;
        free(node);
        return temp;
      }
      Node *succesor = findMin(node->right);
      node->val = succesor->val;
      node->right = _delete(node->right, succesor->val);
    }
    return node;
  }
public:
  void init() {
    root = nullptr;
  }
  void insert(int val) {
    root = _insert(root, val);
  }
  int order(int val) {
    return _order(root, val);
  }
  int search(int val) {
    Node *res = _search(root, nullptr, val);
    if(res != nullptr) {
      return res->val;
    }
    return -1;
  }
};


int main() {

}
