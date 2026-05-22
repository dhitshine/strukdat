#include <bits/stdc++.h>
using namespace std;

const int mxn = 1005;
vector<vector<int>> adj(mxn);

int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  vector<int> indegree(n + 1);
  for(int i = 1; i <= n; i++) {
    for(auto &next : adj[i]) {
      indegree[next]++;
    }
  }
  int node = -1;
  for(int i = 1; i <= n; i++) {
    if(indegree[i] == n - 1 && adj[i].size() == 0) {
      node = i;
      break;
    }
  }
  cout << node;
  return 0;
}
