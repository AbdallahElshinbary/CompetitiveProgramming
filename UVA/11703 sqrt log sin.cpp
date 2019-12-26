#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[1000005];

ll calc(int i) {
	ll &ret = dp[i];
	if(ret != -1) return ret;
	return ret = (calc(i-sqrt(i)) + calc(log(i)) + calc(i*sin(i)*sin(i))) % 1000000;
}

int main() {
	int i;
	memset(dp, -1, sizeof dp);
	dp[0] = 1;
	for(int i=0; i<=1000000; i++) if(dp[i] == -1) calc(i);

	while(cin >> i && i != -1)
		cout << dp[i] << "\n";

	return 0;
}
