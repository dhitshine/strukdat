#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *left, *right, *par;
  string val;
  int _size;
};

struct Tree { // customizable binary tree
  Node *root;
  void init() {
    root = nullptr;
  }
  int size(Node *node) {
    if(node == nullptr) {
      return 0;
    }
    return node->_size;
  }
  Node* create_node(string val) {
    Node* temp = new Node;    // no need to call constructor manually
    temp->val = val;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->par = nullptr;
    temp->_size = 1;
    return temp;
  }
  void insert(string val) {
    Node *temp = create_node(val);
    if(root == nullptr) {
      root = temp;
      return;
    } 
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
      Node *curr = q.front();
      q.pop();
      if(curr->left == nullptr) {
        curr->left = temp;
        curr->left->par = curr;
        break;
      }else {
        q.push(curr->left);
      }
      if(curr->right == nullptr) {
        curr->right = temp;
        curr->right->par = curr;
        break;
      }else {
        q.push(curr->right);
      }
    }
    Node* ancestor = temp->par;
    while(ancestor != nullptr) {
      ancestor->_size++;
      ancestor = ancestor->par;
    }
  }
  Node* search(string val) {
    if(root == nullptr) {
      return nullptr;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
      Node *curr = q.front();
      q.pop();
      if(curr->val == val) {
        return curr;
      }
      if(curr->left != nullptr) {
        q.push(curr->left);
      }
      if(curr->right != nullptr) {
        q.push(curr->right);
      }
    }
    return nullptr;
  }
  int getsize() {
    return size(root);
  }
};

int main() {
  int n;
  Tree tree1, tree2;
  tree1.init();
  tree2.init();
  cin >> n;
  while(n--) {
    string s;
    cin >> s;
    Node *find1 = tree1.search(s);
    Node *find2 = tree2.search(s);
    if(find1 == nullptr) {
      tree1.insert(s);
      cout << s << " masuk Kamus 1!" << endl;
    }else if(find2 == nullptr) {
      tree2.insert(s);
      cout << s << " masuk Kamus 2!" << endl;
    }else {
      cout << s << " tidak bisa masuk Kamus!" << endl;
    }
  }
  cout << "Kamus 1 berisi " << tree1.getsize() << " kata" << endl;
  cout << "Kamus 2 berisi " << tree2.getsize() << " kata" << endl;
}
