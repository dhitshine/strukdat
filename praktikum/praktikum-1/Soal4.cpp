#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), ans;
  for(auto &i : a) cin >> i;
  deque<int> dq;  // nyimpen indeks dengan monotonic increasing order
  for(int i = 0; i < n; i++) {
    while(!dq.empty() && dq.front() <= i - k) {   // hapus yang diluar window
      dq.pop_front();
    }
    while(!dq.empty() && a[dq.back()] >= a[i]) {  // hapus semua nilai yang lebih besar (biar ambil minimum)
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

/*
 window yang berlaku hanya pada [i - k + 1, i]
 */
