#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t,n;
int arr[35], pre[35];
int dp[3][605][605];

int go(int idx, int x, int a, int b) {
	int c = (idx == 0 ? 0 : pre[idx-1]-(a+b));
	if(idx == n) return max(a,max(b,c)) - min(a,min(b,c));

	int &ret = dp[x][a][b];
	if(ret != -1) return ret;

	int o1 = go(idx+1, 0, a+arr[idx], b);
	int o2 = go(idx+1, 1, a, b+arr[idx]);
	int o3 = go(idx+1, 2, a, b);

	return ret = min(o1, min(o2, o3));
}

int main() {
	cin >> t;
	for(int T=1; T<=t; T++){
		cin >> n;
		for(int i=0; i<n; i++) cin >> arr[i];
		pre[0]=arr[0];
		for(int i=1; i<n; i++) pre[i] = arr[i]+pre[i-1];
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", T, go(0,0,0,0));
	}


	return 0;
}
