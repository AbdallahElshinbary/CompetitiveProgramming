#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,m,x;
	while(cin >> n >> m && (n+m)) {
		set<int> s;
		for(int i=0; i<n; i++) {cin >> x; s.insert(x);}
		for(int i=0; i<m; i++) {cin >> x; s.insert(x);}
		cout << n+m-s.size() << "\n";
	}

	return 0;
}



