#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<string>> a;
	vector<string> baru;
	a.push_back(baru);
	while(n--) {
		string p;
		cin >> p;
		if(p == "new") {
			a.push_back(baru);
		}else if(p == "put") {
			int l, y;
			string x;
			cin >> l >> x >> y;
			if(a.size() < l) {
				cout << "Rak " << l << " gak ketemu" << endl;
				continue;
			}
			while(y--) {
        a[l - 1].push_back(x);
      }
		}else {
			int l, z;
			cin >> l >> z;
			if(a.size() < l || a[l - 1].size() < z) {
				cout << "Rak " << l << " urutan " << z << " kosong" << endl;
				continue; 
			}
			l--, z--;
			string menu = a[l][z];
			a[l].erase(a[l].begin() + z);
			cout << "Menu " << menu << " beracun, Sisa rak: " << a[l].size() << endl;
		}
	}
}
