#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<int, int> mp;

void fact(int n) {
	for(int i=2; i*i<=n ; i++)
		while(n%i == 0) n/=i, mp[i]++;
	if(n > 1) mp[n]++;
}

int main() {
	int n,m,ans=0;
	cin >> n >> m;
	if(m%n != 0) {cout << -1; return 0;}
	fact(m/n);
	for(auto x : mp) {
		if(x.first != 2 && x.first != 3) {cout << -1; return 0;}
		ans += x.second;
	}
	cout << ans;

	return 0;
}
