#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e12
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

double RAD(double t) {
	return t*(PI/180);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	double l,w,h,t,ot,lt,rt,xh,xl;
	while(cin >> l >> w >> h >> t) {
		ot = 180 - (90 + t);
		lt = 90 - ot;
		rt = 180 - (90+lt);

		// l/sin(rt) = xh/sin(lt) = b/sin(90)
		xh = (l/sin(RAD(rt))) * sin(RAD(lt));
		if(xh <= h) {
			printf("%.3lf mL\n", (l*w*h) - (0.5 * l * xh * w));
		} else {
			// h/sin(rt) = xl/sin(lt) = b/sin(90)
			lt = ot;
			rt = 180 - (90+lt);
			xl = (h/sin(RAD(rt))) * sin(RAD(lt));
			printf("%.3lf mL\n", (0.5 * xl * h * w));
		}
	}

	return 0;
}




















