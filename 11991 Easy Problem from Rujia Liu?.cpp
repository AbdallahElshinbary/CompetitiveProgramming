#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,x,k,v;
	map<int, vector<int> > mp;
	while(cin >> n >> m) {
		for(int i=1; i<=n; i++) {
			cin >> x;
			mp[x].push_back(i);
		}
		while(m--) {
			cin >> k >> v;
			cout << (mp[v].size() >= k ? mp[v][k-1] : 0) << "\n";
		}
		mp.clear();
	}

	return 0;
}

