#include <bits/stdc++.h>
using namespace std;

int n, m;
const int mxn = 1e3 + 5;
vector<vector<int>> visited(mxn, vector<int> (mxn, 0));
int dx[8] = {1, 0, -1, 0};
int dy[8] = {0, -1, 0, 1};

bool valid(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m);
}

int bfs(vector<vector<int>> &grid, int x, int y) {
  int cnt = 1;
  queue<pair<int, int>> q;
  q.push({x, y});
  visited[x][y] = 1;
  while(!q.empty()) {
    auto [curr_x, curr_y] = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) {
      int next_x = dx[i] + curr_x;
      int next_y = dy[i] + curr_y;
      if(valid(next_x, next_y) && grid[curr_x][curr_y] >= grid[next_x][next_y] && !visited[next_x][next_y]) {
        cnt++;
        visited[next_x][next_y] = 1;
        q.push({next_x, next_y});
      }
    }
  }
  return cnt;
}
int cnt = 0;
void dfs(vector<vector<int>> &grid, int curr_x, int curr_y) {
  visited[curr_x][curr_y] = 1;
  cnt++;
  for(int i = 0; i < 4; i++) {
    int next_x = dx[i] + curr_x;
    int next_y = dy[i] + curr_y;
    if(valid(next_x, next_y) && grid[curr_x][curr_y] >= grid[next_x][next_y] && !visited[next_x][next_y]) {
      dfs(grid, next_x, next_y);
    }
  }
}

int main() {
  int x, y;
  cin >> n >> m >> x >> y;
  vector<vector<int>> grid(n, vector<int> (m));
  for(auto &row : grid) {
    for(auto &i : row) {
      cin >> i;
    }
  }
  // int ans = bfs(grid, x - 1, y - 1);
  dfs(grid, x - 1, y - 1);
  cout << cnt;
  return 0;
}
