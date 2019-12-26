#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,m,x,cnt;
	bool vis[100005];

	while(cin >> n >> m) {
		x = 0, cnt = 1;
		memset(vis, 0, sizeof vis);
		vis[0]=true;

		while(true) {
			x = (x+n)%m;
			if(vis[x]) break;
			vis[x]=true, cnt++;
		}
		printf("%10d%10d    ", n, m);
		if(cnt == m) printf("Good Choice\n\n");
		else printf("Bad Choice\n\n");
	}

	return 0;
}
