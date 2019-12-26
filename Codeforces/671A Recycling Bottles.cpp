#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e12
#define EPS 1e-9
#define PI 3.14159265359
#define mp make_pair
#define sz(s) (int)s.size()

struct Point {
	double x,y;
	Point() : x(0), y(0) {}
	Point(double x, double y) : x(x), y(y) {}
};

double dist(Point &a, Point &b) {
	return hypot(a.x-b.x, a.y-b.y);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	double ax,ay,bx,by,tx,ty;
	cin >> ax >> ay >> bx >> by >> tx >> ty;
	Point a(ax,ay), b(bx,by), t(tx,ty);

	int n;
	double x,y,ans=0;
	pair<double, int> da[100005], db[100005];
	Point arr[100005];

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x >> y;
		arr[i] = Point(x,y);
		da[i] = mp(dist(arr[i], t) - dist(a, arr[i]), i);
		db[i] = mp(dist(arr[i], t) - dist(b, arr[i]), i);
	}

	for(int i=0; i<n; i++)
		ans += 2*dist(arr[i], t);
	if(n == 1) {cout << fixed << setprecision(12) << ans - fmax(da[0].first, db[0].first); return 0;}

	sort(da, da+n, greater<pair<double, int> >());
	sort(db, db+n, greater<pair<double, int> >());


	if(da[0].second != db[0].second)
		ans -= fmax(da[0].first + db[0].first, fmax(da[0].first, db[0].first));
	else {
		double d=-INF;
		d = fmax(d, fmax(da[0].first, da[1].first));
		d = fmax(d, fmax(db[0].first, db[1].first));
		d = fmax(d, da[0].first + db[1].first);
		d = fmax(d, da[1].first + db[0].first);
		ans -= d;
	}

	cout << fixed << setprecision(12) << ans;

	return 0;
}




















