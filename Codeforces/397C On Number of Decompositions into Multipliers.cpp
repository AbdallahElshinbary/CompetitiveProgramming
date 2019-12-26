#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
ll C[18000][501];
map<int, int> mp;

void factorize(int n) {
	int i;
	for(i=2; i*i<=n; i++) {
		while(n%i == 0) mp[i]++, n/=i;
	}
	if(n > 1) mp[n]++;
}

int main() {
	for(int i=0; i<18000; i++) {
		for(int j=0; j<=min(i, 500); j++) {
			if(j == 0 || j == i) C[i][j] = 1;
			else C[i][j] = (C[i-1][j-1] + C[i-1][j])%MOD;
		}
	}

	ll n, x, ans=1;
	cin >> n;
	for(int i=0; i<n; i++) {cin >> x; factorize(x);}
	for(auto m : mp) {
		ans *= C[m.second+n-1][n-1];
		ans %= MOD;
	}
	cout << ans;

	return 0;
}
