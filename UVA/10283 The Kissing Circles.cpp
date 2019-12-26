#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	double r,n,x,y,an,l,A,I,E;
	while(cin >> r >> n) {
		if(n == 1) {
			printf("%.10lf %.10lf %.10lf\n", r,0.0,0.0);
			continue;
		}
		else if(n == 2) x = r/2;
		else x = r*sin(PI/n)/(sin(PI/n)+1);

		l = 2*x;
		an = (n-2) * 180.0 / n;
		y = (PI*x*x)*(an/360)*n;
		A = (l*l*n)/(4*tan(PI/n));
		I = A-y;
		E = (PI*r*r) - ((PI*x*x*n) + I);
		printf("%.10lf %.10lf %.10lf\n", x,I,E);
	}

	return 0;
}
















