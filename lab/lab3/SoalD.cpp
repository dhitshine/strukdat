#include <bits/stdc++.h>
using namespace std;

const int mxn = 1005;
vector<vector<int>> adj(mxn, vector<int> (mxn));
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
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int q;
    cin >> q;
    for(int j = 0; j < q; j++) {
      int v;
      cin >> v;
      adj[i].push_back(v);
    }
  }
  dfs(0);
  for(int i = 0; i < n; i++) {
    if(!visited[i]) {
      cout << "Para peserta LBH terjebak selamanya.";
      return 0;
    }
    
  }
  cout << "Para peserta LBH berhasil keluar!";
  return 0;
}

