/*
 Source: Kalicharan, Advanced Topics in C, p.132 no.18
 */

#include <iostream>
#include <stack>
using namespace std;

stack<int> sort_stack(stack<int> st) {
  stack<int> temp;
  while(!st.empty()) {
    int tmp = st.top();
    st.pop();
    while(!temp.empty() && temp.top() < tmp) {
      st.push(temp.top());
      temp.pop();
    }
    temp.push(tmp);
  }
  return temp;
}

int main() {
  stack<int> st;
  st.push(5);
  st.push(1);
  st.push(2);
  st.push(3);
  stack<int> sorted = sort_stack(st);
  cout << "Before:" << endl;
  while(!st.empty()) {
    cout << st.top() << endl;
    st.pop();
  }
  cout << "After:" << endl;
  while(!sorted.empty()) {
    cout << sorted.top() << endl;
    sorted.pop();
  }
  return 0;
}
