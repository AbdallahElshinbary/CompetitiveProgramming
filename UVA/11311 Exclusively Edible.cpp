#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,m,n,r,c,a,b,d,e;
	cin >> t;
	while(t--) {
		cin >> m >> n >> r >> c;
		a=r, b=m-1-r, d=c, e=n-1-c;
		cout << ((a^b^d^e) == 0 ? "Hansel\n" : "Gretel\n");
	}

	return 0;
}
