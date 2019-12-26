#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-6
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

struct Point {
	double x,y;
	Point(double x, double y) : x(x), y(y) {}
};

double cross(Point &o, Point &a, Point &b) {
    return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}
bool inTriangle(Point &a, Point &b, Point &c, Point t) {
    return (cross(a, b, t)*cross(a, c, t) < EPS)
        && (cross(b, a, t)*cross(b, c, t) < EPS)
        && (cross(c, a, t)*cross(c, b, t) < EPS);
}

int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);

	double sum, arr[6];
	int mnx, mxx, mny, mxy, cnt;
	while(1) {
		sum = cnt = 0;
		for(int i=0; i<6; i++) {cin >> arr[i]; sum += arr[i];}
		if(fabs(sum-0.0) <= EPS) break;

		mnx = ceil(fmin(arr[0], fmin(arr[2], arr[4])));
		mxx = floor(fmax(arr[0], fmax(arr[2], arr[4])));
		mny = ceil(fmin(arr[1], fmin(arr[3], arr[5])));
		mxy = floor(fmax(arr[1], fmax(arr[3], arr[5])));

		mnx = max(1, mnx);
		mxx = min(99, mxx);
		mny = max(1, mny);
		mxy = min(99, mxy);

		Point a(arr[0], arr[1]), b(arr[2], arr[3]), c(arr[4], arr[5]);

		for(int i=mnx; i<=mxx; i++)
			for(int j=mny; j<=mxy; j++)
				if(inTriangle(a,b,c,Point(i,j)))
					cnt++;

		printf("%4d\n", cnt);
	}

	return 0;
}




















