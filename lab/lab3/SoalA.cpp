#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5 + 7;
vector<vector<int>> adj(mxn);
vector<int> visited(mxn, 0);

void dfs(int curr) {
  visited[curr] = 1;
  for(auto &next : adj[curr]) {
    if(!visited[next]) {
      dfs(next);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); 
    adj[v].push_back(u);
  }
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(!visited[i]) {
      dfs(i);
      cnt++;
    }
  }
  if(cnt == 1) {
    cout << "Kompleksitas entitas terbentuk";
  }else {
    cout << "Seluruh kosmik tidak berkaitan, butuh " << cnt - 1 << " lagi";
  }
  return 0;
}
