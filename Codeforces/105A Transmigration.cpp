#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,m,x;
	double k;
	string s;
	map<string, int> mp;

	cin >> n >> m >> k;
	for(int i=0; i<n; i++) {
		cin >> s >> x;
		if(x*k < 100) continue;
		mp[s] = x*(k+0.000000001);
	}

	for(int i=0; i<m; i++) {
		cin >> s;
		if(mp.find(s) == mp.end()) mp[s] = 0;
	}

	cout << mp.size() << "\n";
	for(auto mm : mp) cout << mm.first << " " << mm.second << "\n";

	return 0;
}



