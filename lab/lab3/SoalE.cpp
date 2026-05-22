#include <bits/stdc++.h>
using namespace std;

const int mxn = 105;
vector<vector<int>> adj(mxn);
vector<int> visited(mxn, 0);

void dfs(int start) {
  stack<int> st;
  st.push(start);
  visited[start] = 1;
  while(!st.empty()) {
    int curr = st.top();
    st.pop();
    for(auto &next : adj[curr]) {
      if(!visited[next]) {
        visited[next] = 1;
        st.push(next);
      }
    }
  }
}

struct DSU {
  vector<int> parent;
  vector<int> size;
  void init(int n) {
    parent.resize(n);
    size.resize(n, 1);
    for(int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int root(int x) {
    if(x == parent[x]) {
      return x;
    }
    parent[x] = root(parent[x]);
    return parent[x];
  }
  bool connected(int u, int v) {
    return root(u) == root(v);
  }
  void join(int u, int v) {
    int u_root = root(u);
    int v_root = root(v);
    if(u_root == v_root) {
      return;
    }
    parent[v_root] = u_root;
  }
};

int main() {
  int n, c;
  cin >> n;
  vector<int> a(n);
  for(auto &i : a) {
    cin >> i;
  }
  cin >> c;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      if((a[i] ^ a[j]) % c == 0) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(!visited[i]) {
      dfs(i);
      cnt++;
    }
  }
  /*
  DSU dsu;
  dsu.init(n);
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      if((a[i] ^ a[j]) % c == 0) {
        dsu.join(i, j);
      }
    }
  }
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(i == dsu.root(i)) {
      cnt++;
    }
  }
  */
  cout << cnt;
  return 0;
}
