#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e9
#define EPS 1e-9
#define PI 3.14159265359
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	double d,h,v,e,r,a,x;
	cin >> d >> h >> v >> e;
	r = d/2;
	a = PI*r*r*h;
	x = (PI*r*r*e);

	if(x > v) {cout << "NO"; return 0;}

	double L=0, R=1e4, m, z;
	for(int i=0; i<100; i++) {
		m = (L+R)/2;
		z = a + (m*x) - (m*v);
		if(z <= 0) R = m;
		else L = m;
	}
	cout << "YES\n";
	cout << setprecision(12) << m << "\n";

	return 0;
}
















