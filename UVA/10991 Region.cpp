#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e12
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

double dist(double x1, double y1, double x2, double y2) {
	return hypot(x1-x2, y1-y2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	double r1,r2,r3,a,b,c,x,y,z,s,A,A1,A2,A3;
	cin >> t;
	while(t--) {
		cin >> r1 >> r2 >> r3;
		a = r1+r2, b = r1+r3, c = r2+r3;
		s = (a+b+c)/2;

		x = acos((a*a + b*b - c*c) / (2*a*b));
		y = acos((a*a + c*c - b*b) / (2*a*c));
		z = acos((b*b + c*c - a*a) / (2*b*c));

		A = sqrt(s * (s-a) * (s-b) * (s-c));
		A1 = (x/(2*PI)) * (PI*r1*r1);
		A2 = (y/(2*PI)) * (PI*r2*r2);
		A3 = (z/(2*PI)) * (PI*r3*r3);
		printf("%.9lf\n", A-(A1+A2+A3));
	}

	return 0;
}




















