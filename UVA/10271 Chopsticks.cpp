#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 1e9

int t,k,n;
int arr[5005];
int dp[5005][5005];

int go(int idx, int count) {
	if(count == 0) return 0;
	if(3*count > n-idx) return INF;

	int &ret = dp[idx][count];
	if(ret != -1) return ret;

	int o1 = (arr[idx]-arr[idx+1])*(arr[idx]-arr[idx+1]) + go(idx+2, count-1);
	int o2 = go(idx+1, count);
	return ret = min(o1, o2);
}

int main() {
	cin >> t;
	while(t--) {
		cin >> k >> n;
		for(int i=0; i<n; i++) cin >> arr[i];
		sort(arr, arr+n);

		memset(dp, -1, sizeof dp);
		cout << go(0, k+8) << "\n";
	}

	return 0;
}
