#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int w,s,n=0, W[1005], S[1005], idx[1005];

	while(cin >> w >> s) W[n]=w, S[n]=s, idx[n]=n+1, n++;

	for(int i=0; i<n; i++)
		for(int j=0; j<n-1; j++)
			if(S[j] < S[j+1])
				swap(S[j], S[j+1]), swap(W[j], W[j+1]), swap(idx[j], idx[j+1]);

	int LIS[1005];
	fill(LIS, LIS+1005, 1);

	for(int i=0; i<n; i++)
		for(int j=0; j<i; j++)
			if(W[j] < W[i] && S[j] > S[i])
				LIS[i] = max(LIS[i], 1+LIS[j]);

	int mx = 0, cur;
	for(int i=0; i<n; i++)
		if(mx < LIS[i]) mx = LIS[i], cur=i;
	cout << mx << "\n";

	vector<int> ans; mx--;
	ans.push_back(idx[cur]);

	for(int i=n-1; i>=0; i--) {
		if(LIS[i] == mx && W[i] < W[cur] && S[i] > S[cur]) {ans.push_back(idx[i]); cur=i, mx--;}
	}

	for(int i=(int)ans.size()-1; i>=0; i--) cout << ans[i] << "\n";

	return 0;
}
