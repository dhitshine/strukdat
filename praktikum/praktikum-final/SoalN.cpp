#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  stack<string> st;
  while(n--) {
    string cmd, s;
    cin >> cmd;
    if(cmd == "PUSH") {
      cin >> s;
      st.push(s);
    }else if(cmd == "TOP") {
      if(st.empty()) {
        cout << "KOSONG" << endl;
        continue;
      }
      string curr = st.top();
      cout << curr << endl;
    }else if(cmd == "POP"){
      if(st.empty()) {
        continue;
      }
      st.pop();
    }
  }
}
