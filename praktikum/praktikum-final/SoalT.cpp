#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> visited;
int dx[8] = {1, 1, -1, -1, 0, 0, -1, 1};
int dy[8] = {0, 1, -1, 0, -1, 1, 1, -1};
int n, m, qx, qy, kx, ky, tx, ty;
bool bisa = 0;

bool valid(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < n);
}

void dfs() {
  for(int i = 0; i < n; i++) {
    visited[qx][i] = 1;
    visited[i][qy] = 1;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(abs(i - qx) == abs(j - qy)) {
        visited[i][j] = 1;
      }
    }
  }
  stack<pair<int, int>> st;
  st.push({kx, ky});
  visited[kx][ky] = 1;
  while(!st.empty()) {
    auto [x, y] = st.top();
    st.pop();
    if(x == tx && y == ty) {
      bisa = 1;
      break;
    }
    for(int i = 0; i < 8; i++) {
      int x_next = x + dx[i];
      int y_next = y + dy[i];
      if(valid(x_next, y_next) && !visited[x_next][y_next]) {
        visited[x_next][y_next] = 1;
        st.push({x_next, y_next});
      } 
    }
  }
}

int main() {
  cin >> n >> m >> qx >> qy >> kx >> ky >> tx >> ty;
  qx--, qy--, kx--, ky--, tx--, ty--;
  visited.resize(n, vector<int> (n, 0));
  while(m--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    visited[x][y] = 1;
  }
  dfs();
  if(bisa) {
    cout << "Yay";
  }else {
    cout << "Nay";
  }
  return 0;
}
