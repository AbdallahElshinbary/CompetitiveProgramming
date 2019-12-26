#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
string s;
int dp[1005][1005];

int go(int l, int r) {
	if(l > r) return 0;

	int &ret = dp[l][r];
	if(ret != -1) return ret;

	int x,o1,o2,o3;

	for(int i=r; i>=l; i--) if(s[i] == s[l]) {x=i; break;}
	if(x == l) o1 = 1 + go(l+1,x-1);
	else o1 = 2 + go(l+1,x-1);

	for(int i=l; i<=r; i++) if(s[i] == s[r]) {x=i; break;}
	if(x == r) o2 = 1 + go(x+1,r-1);
	else o2 = 2 + go(x+1,r-1);

	o3 = go(l+1, r-1);

	return ret = max(o1, max(o2, o3));
}

int main() {
	cin >> t;
	cin.ignore();
	while(t--) {
		getline(cin, s);
		memset(dp, -1, sizeof dp);
		cout << go(0, s.size()-1) << "\n";
	}

	return 0;
}
