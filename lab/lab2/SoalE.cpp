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
  Node* _insert(Node *node, int val) {
    if(node == nullptr) {
      return create_node(val);
    }
    if(val == node->val) {
      return node;
    }
    if(val < node->val) {
      node->left = _insert(node->left, val);
    }else {
      node->right = _insert(node->right, val);
    }
    node->height = 1 + max(height(node->left), height(node->right));
    int bf = balance(node);
    if(bf > 1) {              // left imbalance
      if(balance(node->left) >= 0) {  // LL
        return rightrotate(node);
      }else {
        node->left = leftrotate(node->left);  // LR
        return rightrotate(node);
      } 
    } 
    if(bf < -1) {             // right imbalance
      if(balance(node->right) <= 0) {  // RR
        return leftrotate(node);
      }else {
        node->right = rightrotate(node->right);   // RL
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
  void collect(Node *node, int currDist, map<int, long long> &m) {
    if(node == nullptr) {
      return;
    }
    m[currDist] += node->val;
    collect(node->left, currDist - 1, m);
    collect(node->right, currDist + 1, m);
  }
public:
  void init() {
    root = nullptr;
  }
  void insert(int val) {
    root = _insert(root, val);
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
  long long get() {
    map<int, long long> sum;
    collect(root, 0, sum);
    long long ans = 0;
    for(auto &p : sum) {
      ans += p.second * p.second;
    }
    return ans;
  }
};

int main() {
  int n;
  Tree tree;
  tree.init();
  string s;
  while(cin >> s) {
    int x;
    if(s == "Insert") {
      cin >> x;
      tree.insert(x);
    }else {
      long long ans = tree.get();
      cout << ans << endl;
    }
  }
}
