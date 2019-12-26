#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-11
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

struct Point {
	double x,y;
	Point(double x, double y) : x(x), y(y) {}
	bool operator<(Point o) {
		if(fabs(x-o.x) <= EPS) return y < o.y;
		return x < o.x;
	}
};
Point operator-(const Point &a, const Point &b) {
	return Point(a.x-b.x, a.y-b.y);
}
double operator*(const Point &a, const Point &b) {
    return a.x*b.x + a.y*b.y;
}
double operator^(const Point &a, const Point &b) {
    return a.x*b.y - a.y*b.x;
}

double abs(const Point &p) {
    return p*p;
}
double angle(const Point& pivot, const Point& a) {
    return atan2(a.y - pivot.y, a.x - pivot.x);
}
double angle(const Point& a, const Point& o, const Point& b) {
    Point oa = a-o, ob = b-o;
    return acos((oa*ob) / sqrt(abs(oa) * abs(ob)));
}

Point pivot(0,0);
bool angleCMP(Point &a, Point &b) {
	return angle(pivot, a) < angle(pivot, b);
}

int orientation(const Point &a, const Point &b, const Point &c) {
	int res = (a.y-b.y)*(b.x-c.x) - (b.y-c.y)*(a.x-b.x);
	return (res == 0 ? 0 : (res > 0 ? 1 : 2));	//collinear / clock wise / counterclock wise
}
double area(vector<Point> p) {
	double result = 0.0;
	p.push_back(p[0]);
	for (int i = 0; i < (int)p.size()-1; i++)
        result += p[i]^p[i+1];  //cross product
	return fabs(result) / 2.0;
}

vector<Point> ConvexHull(vector<Point> p) {
	if(sz(p) <= 1) return p;

	for(int i=0; i<sz(p); i++)
		if(Point(p[i].y, p[i].x) < Point(p[0].y, p[0].x))	//get bottom-most
			swap(p[0], p[i]);

	pivot = p[0];
	sort(p.begin()+1, p.end(), angleCMP);

	vector<Point> ch;
	ch.push_back(p[0]), ch.push_back(p[1]);

	for(int i=2; i<sz(p); i++) {
		while(sz(ch) > 1 && orientation(ch[sz(ch)-2], ch[sz(ch)-1], p[i]) == 1)	//clock wise
			ch.pop_back();
		ch.push_back(p[i]);
	}
	ch.push_back(ch[0]);	//close the polygon

	return ch;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1,n,x,y;
	double tA, cA;
	while(cin >> n && n) {
		vector<Point> v;
		for(int i=0; i<n; i++) {
			cin >> x >> y;
			v.push_back(Point(x,y));
		}

		tA = area(v);
		cA = area(ConvexHull(v));

		printf("Tile #%d\n", t++);
		printf("Wasted Space = %.2lf %%\n\n", (1 - tA/cA)*100);
	}
}









