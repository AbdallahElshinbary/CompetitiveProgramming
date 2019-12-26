#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,q,l,r,x,p;
ll dp[150005][18], can[150005][18]{};
int arr[100005];

ll calc(int i, int j) {
	if(j == 0) return arr[i];

	ll &ret = dp[i][j];
	if(ret != -1) return ret;

	int c1 = calc(i, j-1);
	int c2 = calc(i+(1<<(j-1)), j-1);
	can[i][j] = can[i][j-1] + can[i+(1<<(j-1))][j-1] + (c1+c2 >= 10);
	return ret = (c1 + c2) % 10;
}

int main() {
	memset(dp, -1, sizeof dp);
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];

	cin >> q;
	while(q--) {
		cin >> l >> r; l--, r--;
		x = r-l+1, p=-1;
		while(x) {x>>=1, p++;}
		if(!p) cout << "0\n";
		else {calc(l, p); cout << can[l][p] << "\n";}
	}

	return 0;
}







