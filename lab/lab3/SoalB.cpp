#include <bits/stdc++.h>
using namespace std;

int n;
const int mxn = 105;
vector<vector<int>> visited(mxn, vector<int> (mxn, 0));
int dx[8] = {1, 0, -1, 0, -1, 1, 1, -1};
int dy[8] = {0, -1, 0, 1, 1, -1, 1, -1};

bool valid(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < n);
}

void dfs(vector<vector<char>> &grid, int curr_x, int curr_y) {
  visited[curr_x][curr_y] = 1;
  for(int i = 0; i < 8; i++){
    int next_x = curr_x + dx[i];
    int next_y = curr_y + dy[i];
    if(valid(next_x, next_y) && grid[next_x][next_y] != '#' && !visited[next_x][next_y]) {
      dfs(grid, next_x, next_y);
    }
  }
}

int main() {
  cin >> n;
  vector<vector<char>> grid(n, vector<char> (n));
  for(auto &row : grid) {
    for(auto &i : row) {
      cin >> i;
    }
  }
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(!visited[i][j] && grid[i][j] != '#') {
        dfs(grid, i, j);
        cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}
