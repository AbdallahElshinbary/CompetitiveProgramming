#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int dp[10005];
	fill(dp, dp+10005, 1e9); dp[0]=0;
	for(int i=1; i<=10000; i++) {
		for(int j=1; j<=100; j++) {
			if(j*j > i) break;
			dp[i] = min(dp[i], 1 + dp[i-j*j]);
		}
	}

	int t,n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}
