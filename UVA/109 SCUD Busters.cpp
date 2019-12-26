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
	Point() : x(0), y(0) {}
	Point(double x, double y) : x(x), y(y) {}
    bool operator<(const Point &o) const {
        if(fabs(x-o.x) < EPS) return y < o.y;
        return x < o.x;
    }
};
Point operator-(const Point &a) {
    return Point(-a.x, -a.y);
}
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
int ccw(const Point &a, const Point &b, const Point &c) {
	int res = (a.y-b.y)*(b.x-c.x) - (b.y-c.y)*(a.x-b.x);
	return (res > 0 ? 0 : 1);
}
bool collinear(const Point &a, const Point &b, const Point &c) {
	return ((a.y-b.y)*(b.x-c.x)) == ((b.y-c.y)*(a.x-b.x));
}
double angle(const Point& pivot, const Point& a) {
    return atan2(a.y - pivot.y, a.x - pivot.x);
}
double angle(const Point& a, const Point& o, const Point& b) {
    Point oa = a-o, ob = b-o;
    return acos((oa*ob) / sqrt(abs(oa) * abs(ob)));
}
int orientation(const Point &a, const Point &b, const Point &c) {
	int res = (a.y-b.y)*(b.x-c.x) - (b.y-c.y)*(a.x-b.x);
	return (res == 0 ? 0 : (res > 0 ? 1 : 2));	//collinear / clock wise / counterclock wise
}

double polygonArea(vector<Point> &p) {
	double result = 0.0;
    p.push_back(p[0]);
	for (int i = 0; i < (int)p.size()-1; i++)
        result += p[i]^p[i+1];
	p.pop_back();
	return fabs(result) / 2.0;
}

bool pointInPolygon(Point pt, const vector<Point> &p) {
	double sum = 0;
	for (int i = 0; i < sz(p)-1; i++) {
		if(collinear(p[i], p[i+1], pt)) return 1;   //with between

		if (ccw(pt, p[i], p[i+1]))
			sum += angle(p[i], pt, p[i+1]);
		else
			sum -= angle(p[i], pt, p[i+1]);
	}

	return fabs(fabs(sum) - 2*PI) < EPS;
}

Point pivot;
bool angleCMP(Point &a, Point &b) {
	return angle(pivot, a) < angle(pivot, b);
}

vector<Point> ConvexHull(vector<Point> p) {
	if(sz(p) <= 1) return p;

	for(int i=0; i<sz(p); i++)
		if(Point(p[i].y, p[i].x) < Point(p[0].y, p[0].x))	//get bottom-most point
			swap(p[0], p[i]);

	pivot = p[0];
	sort(p.begin()+1, p.end(), angleCMP);

	vector<Point> ch;
	ch.push_back(p[0]), ch.push_back(p[1]);

    //Graham Scan
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

	int n,x,y;
	vector<vector<Point> > kingdoms;
	bool fall[25]{};

	while(cin >> n && n != -1) {
		vector<Point> k;
		for(int i=0; i<n; i++) {
			cin >> x >> y;
			k.push_back(Point(x,y));
		}
		pivot = Point(0,0);
		kingdoms.push_back(ConvexHull(k));
	}

	double ans = 0;
	while(cin >> x >> y) {
		for(int i=0; i<sz(kingdoms); i++) {
			if(fall[i]) continue;
			if(pointInPolygon(Point(x,y), kingdoms[i])) {
				fall[i] = 1;
				ans += polygonArea(kingdoms[i]);
			}
		}
	}
	printf("%.2lf\n", ans);

	return 0;
}




















