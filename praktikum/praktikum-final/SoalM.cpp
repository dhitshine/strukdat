#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> tree;

void build(int curr, int n, int &idx) {
  if(curr > n) {
    return;
  }
  build(2 * curr, n, idx);
  tree[curr] = a[idx];
  idx++;
  build(2 * curr + 1, n, idx);
}

int main() {
  int n;
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  tree.resize(n + 1);
  int idx = 0;
  build(1, n, idx);
  vector<int> par(a[n - 1] + 1, -1);
  for(int i = 1; i <= n; i++) {
    if(i == 1) {
      par[tree[i]] = -1;
    }else {
      par[tree[i]] = tree[i / 2];
    }
  }
  for(int i = 0; i < n; i++) {
    cout << par[a[i]] << " ";
  }
  return 0;
}
