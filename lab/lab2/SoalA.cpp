#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  Node *left, *right;
  long long val;
  Node() : val(0), left(nullptr), right(nullptr) {}  
  Node(long long _val) : val(_val), left(nullptr), right(nullptr) {}
  Node(long long _val, Node *_left, Node *_right) : val(_val), left(_left), right(_right) {}
};

Node* insert(Node *root, long long val) {
  Node *temp = new Node(val);
  if(root == nullptr) {
    return temp;
  }
  if(val < root->val) {
    root->left = insert(root->left, val);
  }else {
    root->right = insert(root->right, val);
  }
  return root;
}

Node* find(Node *root, long long val) {
  if(root == nullptr) {
    return nullptr;
  }
  if(val == root->val) {
    return root;
  }
  if(val < root->val) {
    return find(root->left, val);
  }else{
    return find(root->right, val);
  }
}

int depth(Node *root) {
  if(root == nullptr) {
    return 0;
  }
  int l = depth(root->left);
  int r = depth(root->right);
  return max(l, r) + 1;
}

int main() {
  int n;
  Node *root = nullptr;
  cin >> n;
  while(n--) {
    int val;
    cin >> val;
    root = insert(root, val);
  }
  int x;
  cin >> x;
  root = find(root, x);
  int d = depth(root) - 1;
  long long ans = (long long)d*d * 10000;
  cout << ans << endl;
  return 0;
}
