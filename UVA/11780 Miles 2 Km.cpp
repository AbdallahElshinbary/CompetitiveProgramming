#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	map<int, int> mp;
	mp[1]=2, mp[2]=3;

	for(int x = 3; x<=1000; x++) {
		double m,ans = 1e9, d=50, e=x*1.6;
		for(int i=1; i<=x/2; i++) {
			m = mp[i]+mp[x-i];
			if(fabs(e-m) < d) {
				d = fabs(e-m);
				ans = m;
			}
		}
		mp[x] = ans;
	}

	int n;
	while(cin >> n && n) {
		cout << fixed << setprecision(2) << fabs(mp[n]-(n*1.6)) << "\n";
	}

	return 0;
}
