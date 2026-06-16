#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  unordered_map<int, int> key;
  for(int i = 0; i < t; i++) {
    int n;
    cin >> n;
    while(n--) {
      int x;
      cin >> x;
      key[x] = i;
    }
  }
  queue<int> order;
  vector<queue<int>> q(t);
  vector<int> in_queue(t, 0);
  string cmd;
  while(cin >> cmd) {
    if(cmd == "ENQUEUE") {
      int x;
      cin >> x;
      int id = key[x];
      if(!in_queue[id]) {
        order.push(id);
        in_queue[id] = 1;
      }
      q[id].push(x);
    }else {
      int id = order.front();
      cout << q[id].front() << endl;
      q[id].pop();
      if(q[id].empty()) {
        order.pop();
        in_queue[id] = 0;
      }
    }
  }
  return 0;
}

