#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> par;
  vector<int> sz;
  int component;
  void init(int n) {
    par.resize(n);
    sz.resize(n, 1);
    component = n - 1;
    for(int i = 0; i < n; i++) {
      par[i] = i;
    }
  }
  int find(int x) {
    if(x == par[x]) {
      return x;
    }
    return par[x] = find(par[x]);
  }
  bool connected(int u, int v) {
    return (find(u) == find(v));
  }
  void join(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) {
      return;
    }
    if(sz[u] < sz[v]) {
      swap(u, v);
    }
    sz[u] += sz[v];
    par[v] = u;
    component--;
  }
};

int main() {
  DSU dsu;
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edge(m + 1);
  for(int i = 1; i <= m; i++) {
    cin >> edge[i].first >> edge[i].second;
  }
  int q;
  cin >> q;
  vector<int> query(q);
  vector<int> remove(m + 1, 0);
  for(auto &i : query) {
    cin >> i;
    remove[i] = 1;    // remove edge at idx i
  }
  dsu.init(n + 1);
  for(int i = 1; i <= m; i++) {
    if(!remove[i]) {
      dsu.join(edge[i].first, edge[i].second);
    }
  }
  vector<int> ans(q);
  for(int i = q - 1; i >= 0; i--) {
    ans[i] = dsu.component;
    int idx = query[i];
    dsu.join(edge[idx].first, edge[idx].second);
  }

  for(auto &i : ans) {
    cout << i << endl;
  }
  return 0;
}
