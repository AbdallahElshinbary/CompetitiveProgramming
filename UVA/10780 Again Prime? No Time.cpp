#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,n,m,x,ans,c1,c2;
	cin >> t;
	for(int T=1; T<=t; T++) {
		cin >> m >> n;
		ans=1e9;
		for(int i=2; i*i<=m; i++) {
			if(m%i == 0) {
				c1=c2=0;
				while(m%i ==0) c1++, m/=i;
				x = i;
				while(true) {
					c2 += (n/x);
					x *= i;
					if(n/x == 0) break;
				}
				ans = min(ans, c2/c1);
			}
		}
		if(m > 1) {
			x = m, c1=c2=0;
			while(true) {
				c2 += (n/x);
				x *= m;
				if(n/x == 0) break;
			}
			ans = min(ans, c2);
		}
		printf("Case %d:\n", T);
		if(ans == 0) printf("Impossible to divide\n");
		else printf("%d\n", ans);
	}

	return 0;
}
