#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,x;
	while(cin >> n >> m && n != 0 && m != 0) {
		set<int> s;

		for(int i=0; i<n+m; i++) {
			cin >> x;
			s.insert(x);
		}

		cout << (n+m)-s.size() << "\n";
	}

	return 0;
}

