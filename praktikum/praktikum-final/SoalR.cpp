#include <bits/stdc++.h>
using namespace std;

int main() {
  priority_queue<int, vector<int>, greater<int>> pq;
  int n;
  cin >> n;
  while(n--) {
    string s;
    int x;
    cin >> s;
    if(s == "ADD") {
      cin >> x;
      pq.push(x);
    }else {
      if(pq.empty()) {
        cout << -1 << endl;
        continue;
      }
      int d = pq.top();
      pq.pop();
      cout << d << endl;
    }
  }
  return 0;
}
