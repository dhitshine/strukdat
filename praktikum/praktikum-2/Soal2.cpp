#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v;
  set<int> s;
  while(n--) {
    int x;
    cin >> x;
    v.push_back(x);
    if(s.find(x) != s.end()) {    // kalo ketemu
      v.pop_back();
    }else {
      s.insert(x);
    }
  }
  for(int val : v) {
    cout << val << " ";
  }
}
