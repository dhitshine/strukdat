#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int t, n, m;

bool valid(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
  cin >> t;
  while(t--) {
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
      cin >> grid[i];
    }
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int> (m, -1));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(grid[i][j] == '1') {
          dist[i][j] = 0;
          q.push({i, j});
        }
      }
    }
    while(!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(valid(next_x, next_y) && dist[next_x][next_y] == -1) {
          dist[next_x][next_y] = dist[x][y] + 1;
          q.push({next_x, next_y});
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cout << dist[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
