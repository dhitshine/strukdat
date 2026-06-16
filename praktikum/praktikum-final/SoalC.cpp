#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  deque<string> dq;
  while(n--) {
    string cmd, s;
    cin >> cmd;
    if(cmd == "PUSH_BACK") {
      cin >> s;
      dq.push_back(s);
    }else if(cmd == "PUSH_FRONT") {
      cin >> s;
      dq.push_front(s);
    }else if(cmd == "POP_BACK") {
      if(dq.empty()) {
        continue;
      }
      dq.pop_back();
    }else if(cmd == "POP_FRONT") {
      if(dq.empty()) {
        continue;
      }
      dq.pop_front();
    }
  }
  if(dq.empty()) {
    cout << "KOSONG" << endl;
    return 0;
  }
  while(!dq.empty()) {
    cout << dq.front() << " ";
    dq.pop_front();
  }
  return 0;
}
