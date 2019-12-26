#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;


int main() {
	ll m,n,tmp;
	while(cin >> m && m) {
		ll ans=LONG_MAX;
		for(int i=0; i<=35; i++) {
			n = powl(2, i);
			for(int j=0; j<=35; j++) {
				tmp = n*powl(3, j);
				if(tmp >= m) {
					ans = min(ans, tmp);
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
