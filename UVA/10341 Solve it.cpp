#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const double EPS = 1e-5;

int main() {
	int p,q,r,s,t,u;
	while(cin >> p >> q >> r >> s >> t >> u) {
		double st=0, en=1, x, res;
		for(int i=0; i<100; i++) {
			x = (st+en)/2;
			res = (p*exp(-x)) + (q*sin(x)) + (r*cos(x)) + (s*tan(x)) + (t*x*x) + u;
			if(res > 0) st = x;
			else en = x;
		}
		res = (p*exp(-x)) + (q*sin(x)) + (r*cos(x)) + (s*tan(x)) + (t*x*x) + u;
		if(fabs(res-0) > EPS) cout << "No solution\n";
		else cout << fixed << setprecision(4) << x << "\n";
	}

	return 0;
}
