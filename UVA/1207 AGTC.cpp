#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string x,y;
int n,m,s1,s2;
int dp[1005][1005];

int go(int a, int b) {
	if(a == n) return m-b;
	if(b == m) return n-a;

	int &ret = dp[a][b];
	if(ret != -1) return ret;

	if(x[a] == y[b]) return ret = go(a+1,b+1);

	int o1 = 1 + go(a, b+1);
	int o2 = 1 + go(a+1, b);
	int o3 = 1 + go(a+1, b+1);

	return ret = min(o1, min(o2, o3));
}

int main() {
	while(cin >> n >> x >> m >> y) {
		memset(dp, -1, sizeof dp);
		cout << go(0,0) << "\n";
	}

	return 0;
}
