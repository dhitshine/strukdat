#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), ans;
  for(auto &i : a) cin >> i;
  deque<int> dq;
  for(int i = 0; i < n; i++) {
    while(!dq.empty() && dq.front() <= i - k) {
      dq.pop_front();
    }
    while(!dq.empty() && a[dq.back()] <= a[i]) {
      dq.pop_back();
    }
    dq.push_back(i);
    if(i >= k - 1) {
      ans.push_back(a[dq.front()]);
    }
  }
  for(auto &i : ans) {
    cout << i << " ";
  }
  return 0;
}

