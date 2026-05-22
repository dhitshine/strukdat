#include <bits/stdc++.h>
using namespace std;

struct Data {
  string nama, asal;
  int umur;
};

struct Node {
  Node *left, *right;
  Data data;
};

struct Tree {
  Node *root;
  void init() {
    root = nullptr;
  }
  void insert(Data data) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
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
        return;
      }else {
        q.push(curr->left);
      }
      if(curr->right == nullptr) {
        curr->right = temp;
        return;
      }else {
        q.push(curr->right);
      }
    }
    
  }
  Node* search(string nama) {
    if(root == nullptr) {
      return nullptr;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
      Node *curr = q.front();
      q.pop();
      if(curr->data.nama == nama) {
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
};

int main() {
  int n;
  Tree tree;
  tree.init();
  cin >> n;
  while(n--) {
    Data data;
    string temp;
    cin >> temp >> data.nama;
    cin >> temp >> data.umur;
    cin >> temp >> data.asal;
    tree.insert(data);
  }
  int q;
  cin >>  q;
  while(q--) {
    string nama;
    cin >> nama;
    Node *res = tree.search(nama); // asumsi: pasti selalu ketemu
    cout << "Usia: " << res->data.umur << endl;
    cout << "Asal: " << res->data.asal << endl;
  }
}
