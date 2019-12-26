#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t=1,Z,I,M,L,ans;
	bool vis[10005];

	while(cin >> Z >> I >> M >> L && (Z+I+M+L)) {
		vis[L]=true, ans = 0;
		memset(vis, 0, sizeof vis);
		while(true) {
			L = (Z*L+I)%M;
			if(vis[L]) break;
			vis[L] = true, ans++;
		}
		printf("Case %d: %d\n", t++, ans);
	}

	return 0;
}
