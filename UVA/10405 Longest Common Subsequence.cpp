#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string a,b;
int s1,s2;
int dp[1005][1005];

int go(int x, int y) {
	if(x == s1 || y == s2) return 0;

	int &ret = dp[x][y];
	if(ret != -1) return ret;
	ret = 0;

	if(a[x] == b[y]) ret = 1 + go(x+1, y+1);
	else ret = max(go(x,y+1), go(x+1,y));

	return ret;
}

int main() {
	while(getline(cin, a) && getline(cin, b)) {
		s1 = (int)a.size(), s2 = (int)b.size();
		memset(dp, -1, sizeof dp);
		cout << go(0,0) << "\n";
	}

	return 0;
}
