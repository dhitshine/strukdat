#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *children[26];
  bool isleaf;
  int cnt;
};

Node *create() {
  Node *temp = new Node;
  temp->isleaf = false;
  temp->cnt = 0;
  for(int i = 0; i < 26; i++) {
    temp->children[i] = nullptr;
  }
  return temp;
}

void insert(Node *root, string w) {
  Node *node = root;
  for(char c : w) {
    int idx = c - 'a';
    if(node->children[idx] == nullptr) {
      node->children[idx] = create();
    }
    node->children[idx]->cnt++;
    node = node->children[idx];
  }
  node->isleaf = true;
}

int pref(Node *root, string w) {
  Node *node = root;
  for(char c : w) {
    int idx = c - 'a';
    if(node->children[idx] == nullptr) {
      return 0;
    }
    node = node->children[idx];
  }
  return node->cnt;
}

int main() {
  Node *root = create();
  int n;
  cin >> n;
  while(n--) {
    string s;
    cin >> s;
    insert(root, s);
  }
  int q;
  cin >> q;
  while(q--) {
    string s;
    cin >> s;
    int ans = pref(root, s);
    cout << ans << endl;
  }
  return 0;
}
