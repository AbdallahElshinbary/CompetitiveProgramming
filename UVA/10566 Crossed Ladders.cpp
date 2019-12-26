#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	double x, y, c, m;
	while(cin >> x >> y >> c) {
		double s=1, e=min(x,y);
		for(int i=0; i<200; i++) {
			m = (s+e)/2;
			double l = sqrt((x*x)-(m*m));
			double r = sqrt((y*y)-(m*m));
			double x = (l*r)/(l+r);
			if(x < c) e = m;
			else s = m;
		}
		cout << fixed << setprecision(3) << m << "\n";
	}

	return 0;
}
