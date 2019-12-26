#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[1005][1005];

int solve(int last, int n) {
	int &ret = dp[last][n];
	if(ret != -1) return ret;

	if(n == 0) return ret = 0;

	int x;
	if(last == 0) x = n-1;
	else x = min(n, 2*last);

	for(int i=1; i<=x; i++) {
		if(!solve(i, n-i)) {return ret = 1;}
	}
	return ret = 0;
}

int main() {
	int n;
	while(cin >> n && n) {
		memset(dp, -1, sizeof dp);
		cout << (solve(0, n) ? "Alicia\n" : "Roberto\n");
	}

	return 0;
}
