#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int arr[105];
int dp[105][3];

int go(int idx, int last) {
	if(idx == n) return 0;

	int &ret = dp[idx][last];
	if(ret != -1) return ret;

	if(arr[idx] == 0) return ret = 1 + go(idx+1, 0);
	if(arr[idx] == 1) {
		if(last == 2) return ret = 1 + go(idx+1, 0);
		else return ret = min(go(idx+1, 2), 1+go(idx+1, 0));
	}
	if(arr[idx] == 2) {
		if(last == 1) return ret = 1 + go(idx+1, 0);
		else return ret = min(go(idx+1, 1), 1+go(idx+1, 0));
	}

	if(last == 1) return ret = min(go(idx+1, 2), 1+go(idx+1, 0));
	else if(last == 2) return ret = min(go(idx+1, 1), 1+go(idx+1, 0));
	else return ret = min(go(idx+1, 1), min(go(idx+1, 2), 1+go(idx+1, 0)));
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	memset(dp, -1, sizeof dp);
	cout << go(0, 0);

	return 0;
}
