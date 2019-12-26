#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,x,y,ans=1e9;
	cin >> n;
	map<int, int> f,b;
	for(int i=0; i<n; i++) {cin >> x >> y; f[x]++; if(x != y) b[y]++;}
	n = ceil(n*1.0/2);
	for(auto m : f)
		if(m.second + b[m.first] >= n) ans = min(ans, max(0, n-m.second));
	for(auto m : b)
		if(m.second + f[m.first] >= n) ans = min(ans, max(0, n-f[m.first]));
	cout << (ans == 1e9 ? -1 : ans);


	return 0;
}

