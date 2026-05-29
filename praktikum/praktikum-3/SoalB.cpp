#include <bits/stdc++.h>
using namespace std;

const int mxn = 1005;
vector<vector<int>> adj(mxn);
vector<int> indegree(mxn), outdegree(mxn);

int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    outdegree[u]++;
  }
  for(int i = 1; i <= n; i++) {
    for(auto &next : adj[i]) {
      indegree[next]++;
    }
  }
  int node = -1;
  for(int i = 1; i <= n; i++) {
    if(indegree[i] == n - 1 && outdegree[i] == 0) {
      node = i;
      break;
    }
  }
  cout << node;
  return 0;
}
