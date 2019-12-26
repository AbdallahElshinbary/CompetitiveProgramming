#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e12
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	double a,b,c,s,A,r1,r2,x,y,z;
	while(cin >> a >> b >> c) {
		s = (a+b+c)/2;
		A = sqrt(s * (s - a) * (s - b) * (s - c));
		r1 = A/s;
		r2 = (a*b*c) / (4*A);
		x = PI*r1*r1;
		y = A-x;
		z = PI*r2*r2 - A;
		printf("%.4lf %.4lf %.4lf\n", z,y,x);
	}
	return 0;
}




















