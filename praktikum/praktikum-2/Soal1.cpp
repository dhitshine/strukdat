#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val, depth;
  Node *left, *right;
};

struct Tree { // BST
private:
  Node *root;
  int depth(Node *node) {
    if(node == nullptr) {
      return 0;
    }
    return node->depth;
  }
  Node* create_node(int val) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->left = nullptr;
    node->right = nullptr;
    node->val = val;
    node->depth = 1;
    return node;
  }
  Node* _insert(Node *node, int val) {
    if(node == nullptr) {
      return create_node(val);
    }
    if(val < node->val) {
      node->left = _insert(node->left, val);
    }else {
      node->right = _insert(node->right, val);
    }
    node->depth = 1 + max(depth(node->left), depth(node->right));
    return node;
  }
  Node* _search(Node *node, Node *par, int val) {
    if(node == nullptr) {
      return nullptr;
    }
    if(par != nullptr && val == node->val + par->val) {
      return node;
    }
    Node *found = _search(node->left, node, val);
    if(found != nullptr) {
      return found;
    }
    return _search(node->right, node, val);
  }
  int freq(Node *node, int val) {
    if(node == nullptr) {
      return 0;
    }
    if(val < node->val) {
      return freq(node->left, val);
    }else if(val > node->val) {
      return freq(node->right, val);
    }else {
      return 1 + freq(node->right, val);
    }
  }
  Node* findMin(Node *node) {
    while(node->left != nullptr) {
      node = node->left;
    }
    return node;
  }
  Node* findMax(Node *node) {
    while(node->right != nullptr) {
      node = node->right;
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
      if(node->right == nullptr) {
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
  void _inorder(Node *node) {
    if(node != nullptr) {
      _inorder(node->left);
      cout << node->val << " ";
      _inorder(node->right);
    }
  }
  void _preorder(Node *node) {
    if(node != nullptr) {
      cout << node->val << " ";
      _preorder(node->left);
      _preorder(node->right);
    }
  }
  void _postorder(Node *node) {
    if(node != nullptr) {
      _postorder(node->left);
      _postorder(node->right);
      cout << node->val << " ";
    }
  }

public:
  void init() {
    root = nullptr;
  }
  bool search(int val) {
    Node* res = _search(root, nullptr, val);
    if(res != nullptr) {
      return true;
    }
    return false;
  }
  void insert(int val) {
    root = _insert(root, val);
  }
  void inorder() {
    _inorder(root);
  }
  void preorder() {
    _preorder(root);
  }
  void postorder() {
    _postorder(root);
  }
  int getmin() {
    Node *temp = findMin(root);
    if(temp == nullptr) {
      return 0;
    }
    return temp->val;
  }
  int getmax() {
    Node *temp = findMax(root);
    if(temp == nullptr) {
      return 0;
    }
    return temp->val;
  }
  int getdepth() {
    return root->depth;
  }
  int getfreq(int val) {
    return freq(root, val);
  }
};

int main() {
  int n;
  Tree tree;
  tree.init();
  cin >> n;
  while(n--) {
    int x;
    cin >> x;
    tree.insert(x);
  }
  int val;
  cin >> val;
  if(tree.search(val)) {
    cout << "YES" << endl;
  }else {
    cout << "NO" << endl;
  }
}
