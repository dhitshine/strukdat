#include <bits/stdc++.h>
#define endl '\n'
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
  int n, q;
  cin >> n >> q;
  vector<pair<long long, long long>> p(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  vector<pair<long long, pair<int, int>>> edge;
  for(int i = 1; i <= n; i++) {
    auto [xi, yi] = p[i];
    for(int j = i + 1; j <= n; j++) {
      auto [xj, yj] = p[j];
      long long dx = xi - xj;
      long long dy = yi - yj;
      long long dist = dx * dx + dy * dy;
      edge.push_back({dist, {i, j}});
    }
  }
  vector<pair<long long, int>> query(q);
  for(int i = 0; i < q; i++) {
    cin >> query[i].first;
    query[i].second = i;
  }
  sort(edge.begin(), edge.end());
  sort(query.begin(), query.end());
  vector<int> ans(q);
  int j = 0;
  int total_edge = edge.size();
  dsu.init(n + 1);
  for(int i = 0; i < q; i++) {
    auto [dist, idx] = query[i];
    while(j < total_edge && edge[j].first <= dist) {
      dsu.join(edge[j].second.first, edge[j].second.second);
      j++;
    }
    ans[idx] = dsu.component;
  }
  for(auto &i : ans) {
    cout << i << endl;
  }
  return 0;
}
