#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int arr[1005];
int dp[1005][1005];

int go(int q, int x, int offset) {
	if(q == 2) return max(arr[x], arr[x+offset+1]);
	if(q == 1) return arr[x];
	if(q == 0) return 0;

	int &ret = dp[q][x];
	if(ret != -1) return ret;

	int o1 = max(arr[x], arr[offset+x+1]) + go(q-2, offset+x+2, 0);
	int o2 = max(arr[x], arr[offset+x+2]) + go(q-2, offset+x+1, 1);
	int o3 = max(arr[offset+x+1], arr[offset+x+2]) + go(q-2, x, offset+2);

	return ret = min(o1, min(o2, o3));
}

void trace(int q, int x, int offset) {
	if(q == 2) {cout << x+1 << " " << x+offset+1+1 << "\n"; return;}
	if(q == 1) {cout << x+1 << "\n"; return;}
	if(q == 0) return;

	int o1 = max(arr[x], arr[offset+x+1]) + go(q-2, offset+x+2, 0);
	int o2 = max(arr[x], arr[offset+x+2]) + go(q-2, offset+x+1, 1);
	int o3 = max(arr[offset+x+1], arr[offset+x+2]) + go(q-2, x, offset+2);
	int op = go(q, x, offset);

	if(op == o1) {
		cout << x+1 << " " << offset+x+1+1 << "\n";
		trace(q-2, offset+x+2, 0);
		return;
	}
	else if(op == o2) {
		cout << x+1 << " " << offset+x+2+1 << "\n";
		trace(q-2, offset+x+1, 1);
		return;
	}
	else {
		cout << offset+x+1+1 << " " << offset+x+2+1 << "\n";
		trace(q-2, x, offset+2);
		return;
	}
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	memset(dp, -1, sizeof dp);
	cout << go(n, 0, 0) << "\n";
	trace(n, 0, 0);

	return 0;
}









