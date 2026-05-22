#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<int> pq;
	stack<int> st;
	while(n--) {
		string p;
		cin >> p;
		if(p == "PLAN") {
			int x;
			cin >> x;
			pq.push(x);
		}else if(p == "MOOD") {
			int x;
			cin >> x;
			st.push(x);
		}else {
			if(pq.empty()) {
				cout << "No one is going out" << endl;
				continue;
			}
			if(st.empty())	{			// kalo ga ada mood boost
				cout << pq.top() << endl;
			}else {
				cout << pq.top() + st.top() << endl;
			}
			pq.pop();
			while(!st.empty()) {	// balik normal
				st.pop();
			}
		}
	}
}

