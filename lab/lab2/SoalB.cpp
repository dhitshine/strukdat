#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *left, *right;
  int val, height;
};

struct Tree { // AVL
private:
  Node *root;
  Node* create_node(int val) {
    Node *node = (Node*) malloc(sizeof(Node));
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
  int balance(Node *node) {
    if(node == nullptr) {
      return 0;
    }
    return height(node->left) - height(node->right);
  }
  Node* rightrotate(Node *node) {
    Node *newroot = node->left;
    Node *rightchild = newroot->right; // rightchild of newroot
    newroot->right = node;
    node->left = rightchild;
    node->height = 1 + max(height(node->left), height(node->right));
    newroot->height = 1 + max(height(newroot->left), height(newroot->right));
    return newroot;
  }
  Node* leftrotate(Node *node) {
    Node *newroot = node->right;
    Node *leftchild = newroot->left;  // leftchild of newroot
    newroot->left = node;
    node->right = leftchild;
    node->height = 1 + max(height(node->left), height(node->right));
    newroot->height = 1 + max(height(newroot->left), height(newroot->right));
    return newroot;
  }
  Node* _insert(Node *node, int val, int &flags) {
    Node *temp = create_node(val);
    if(node == nullptr) {
      return temp;
    }
    if(val < node->val) {
      node->left = _insert(node->left, val, flags);
    }else {
      node->right = _insert(node->right, val, flags);
    }
    node->height = 1 + max(height(node->left), height(node->right));
    int bf = balance(node);
    if(bf > 1) {
      flags = 1;
      if(balance(node->left) >= 0) {
        return rightrotate(node);
      }else {
        node->left = leftrotate(node->left);
        return rightrotate(node);
      }
    }
    if(bf < -1) {
      flags = 1;
      if(balance(node->right) <= 0) {
        return leftrotate(node);
      }else {
        node->right = rightrotate(node->right);
        return leftrotate(node);
      }
    }
    return node;
  }
  Node* _search(Node *node, int val) {
    if(node == nullptr || val == node->val) {
      return node;
    }
    if(val < node->val) {
      return _search(node->left, val);
    } else {
      return _search(node->right, val);
    }
  }
  void _inorder(Node *node) {
    if(node != nullptr) {
      _inorder(node->left);
      cout << node->val << " ";
      _inorder(node->right);
    }
  }
public:
  void init() {
    root = nullptr;
  }
  void insert(int val, int &flags) {
    root = _insert(root, val, flags);
  }
  int search(int val) {
    Node *res = _search(root, val);
    if(res != nullptr) {
      return res->val;
    }
    return -1;
  }
  void inorder() {
    _inorder(root);
  }
};

int main() {
  string s;
  int n, flags = 0;
  Tree tree;
  tree.init();
  getline(cin, s);
  cin >> n;
  while(n--) {
    int x;
    cin >> x;
    tree.insert(x, flags);
  }
  if(flags) {
    cout << s << " is suspicious, hang this person now!" << endl;
  }else {
    cout << s << " is innocent." << endl;
    tree.inorder();
  }
  return 0;
}
