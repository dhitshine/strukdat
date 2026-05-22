/*
 Source: Kalicharan, Advanced Topics in C, p.132 no.17
 */

#include <iostream>
#include <queue>
using namespace std;

struct Stack {
  queue<int> q1, q2;
  void push(int val) {
    q2.push(val);
    while(!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
  }
  void pop() {
    if(q1.empty()) {
      return;
    }
    q1.pop();
  }
  int top() {
    if(q1.empty()) {
      return -1;
    }
    return q1.front();
  }
  int size() {
    return q1.size();
  }
  bool empty() {
    return q1.size() == 0;
  }
};

int main() {
  Stack st; 
  st.push(1);
  st.push(2);
  st.push(5);
  while(!st.empty()) {
    cout << st.top() << endl;
    st.pop();
  }
  return 0;
}
