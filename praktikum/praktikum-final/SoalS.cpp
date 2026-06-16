#include <bits/stdc++.h>
using namespace std;

int n;

pair<int, int> dfs(vector<int> &a, int curr) {
  if(curr > n || a[curr] == -1) {
    return {0, 0};
  }
  auto [take_left, skip_left] = dfs(a, 2 * curr);
  auto [take_right, skip_right] = dfs(a, 2 * curr + 1);

  int take_curr = a[curr] + skip_left + skip_right;
  int skip_curr = max(take_left, skip_left) + max(take_right, skip_right);
  return {take_curr, skip_curr};
}

int main() {
  cin >> n;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  auto [take, skip] = dfs(a, 1);
  cout << max(take, skip);
  return 0;
}
