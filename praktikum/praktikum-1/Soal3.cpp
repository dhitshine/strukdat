#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  queue<int> q1, q2;
  for(int i = 0; i < (int)s.length(); i++) {
    if(s[i] == 'S') {
      q1.push(i);
    }else {
      q2.push(i);
    }
  }
  while(!q1.empty() && !q2.empty()) {
    int n = q1.size() + q2.size();
    int s_front = q1.front(), d_front = q2.front();
    if(s_front < d_front) {
      q1.push(s_front + n);
    }else {
      q2.push(d_front + n);
    }
    q1.pop();
    q2.pop();
  }
  if(q1.empty()) {
    cout << "Darsu";
  }else {
    cout << "Sudar";
  }
  return 0;
}
/*
 optimal play:
 nyerang tetangga dahulu
 */
