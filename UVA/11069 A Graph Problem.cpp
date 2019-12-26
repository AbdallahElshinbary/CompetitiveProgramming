#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
	int MAX = 76;
	int dp[MAX+1]{};
	dp[MAX-1] = dp[MAX-2] = dp[MAX-3] = 1;
	for(int i=MAX-4; i>=0; i--)
		dp[i] = dp[i+2] + dp[i+3];

	int n;
	while(cin >> n) cout << dp[MAX-n] + dp[MAX-n+1] << "\n";

	return 0;
}
