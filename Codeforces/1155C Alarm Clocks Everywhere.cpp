#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n,m,x,p,f,g=0;
	cin >> n >> m;
	cin >> p;
	f = p;
	for(int i=1; i<n; i++) {
		cin >> x;
		g = __gcd(g, x-p);
		p = x;
	}

	for(int i=0; i<m; i++) {
		cin >> x;
		if(g%x == 0) {
			cout << "YES\n";
			cout << f << " " << i+1;
			return 0;
		}
	}
	cout << "NO";

	return 0;
}
































