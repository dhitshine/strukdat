#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5 + 5;
const int LOG = 19;
vector<vector<int>> adj(mxn);
vector<int> depth(mxn, 0);
vector<vector<int>> up(mxn, vector<int> (LOG));

void dfs(int curr, int par) {
  up[curr][0] = par;
  for(int i = 1; i < LOG; i++) {
    up[curr][i] = up[up[curr][i - 1]][i - 1];     // 2^k-th ancestor of binary tree
  }
  for(auto &next : adj[curr]) {
    if(next != par) {
      depth[next] = depth[curr] + 1;
      dfs(next, curr);
    }
  }
}

int lca(int u, int v) {
  if(depth[u] < depth[v]) {
    swap(u, v);
  }
  int k = depth[u] - depth[v];
  for(int i = 0; i < LOG; i++) {
    if(k & (1 << i)){      // kalo bit nya hidup, naik sebanyak 2^i
      u = up[u][i];
    }
  }
  if(u == v) {
    return u;
  }
  for(int i = LOG - 1; i >= 0; i--) {   // naik sampai berada tepat dibawah LCA
    if(up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return up[u][0];
}

int main() {
  int n, q;
  cin >> n >> q;
  for(int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }
  dfs(1, 1);
  while(q--) {
    int u, v;
    cin >> u >> v;
    cout << lca(u, v) << endl;
  }
  return 0;
}
