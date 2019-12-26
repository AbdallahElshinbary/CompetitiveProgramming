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

	double x1,y1,x2,y2,x3,y3,a,b,c,r,A;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
		a = dist(x1,y1,x2,y2);
		b = dist(x1,y1,x3,y3);
		c = dist(x2,y2,x3,y3);
		A = abs((x1*(y2-y3) +  x2*(y3-y1) +  x3*(y1-y2)) / 2);
		r = a*b*c / (4*A);
		cout << fixed << setprecision(2) << 2*PI*r << "\n";
	}

	return 0;
}




















