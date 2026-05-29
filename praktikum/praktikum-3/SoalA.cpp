#include <bits/stdc++.h>
using namespace std;

const int mxn = 1005;
bool bisa = 0;
int cnt = 0;
int n, m, a, b;
vector<vector<int>> adj(mxn);
vector<int> visited(mxn, 0);

void dfs(int curr) {
  visited[curr] = 1;
  cnt++;
  if(curr == b) {
    bisa = 1;
    return;
  }
  for(int i = adj[curr].size() - 1; i >= 0; i--) {
    int next = adj[curr][i];
    if(!visited[next] && !bisa) {
      dfs(next);
    }
  }
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> a >> b;
  dfs(a);
  if(bisa) {
    cout << "Ya " << cnt;
  }else {
    cout << "Tidak";
  }
  return 0;
}
