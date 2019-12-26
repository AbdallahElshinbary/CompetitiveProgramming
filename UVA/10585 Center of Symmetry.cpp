#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<double, double> ii;

#define INF 1e9
#define EPS 1e-9
#define PI 3.14159265359
#define mp make_pair
#define sz(s) (int)s.size()

struct Point{
    double x, y;
    Point(double x, double y):x(x), y(y){}
    Point():x(0), y(0){}
};

//------------------------operators---------------------------

//addition
Point operator+(const Point &a, const Point &b){
    return Point(a.x+b.x, a.y+b.y);
}
//subtraction
Point operator-(const Point &a, const Point &b){
    return Point(a.x-b.x, a.y-b.y);
}

//dot product
double operator*(const Point &a, const Point &b){
    return a.x*b.x + a.y*b.y;
}

//cross product
double operator^(const Point &a, const Point &b){
    return a.x*b.y - a.y*b.x;
}
//multiplication by a factor
Point operator*(const double factor, const Point & p){
    return Point(factor * p.x, factor * p.y);
}

Point operator*(const Point & p, const double factor){
    return Point(factor * p.x, factor * p.y);
}

Point rotate(const Point &p, double an){
    return Point(p.x * sin(an) - p.y * cos(an), p.x * cos(an) + p.y * sin(an));
}

Point rotate(const Point &p, double an, Point& around){
    return rotate(p - around, an) + around;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t,n,cnt;
	double x,y,mx,my;
	map<ii, bool> points;
	cin >> t;
	while(t--) {
		cin >> n;
		mx = my = cnt = 0;
		for(int i=0; i<n; i++) {
			cin >> x >> y;
			Point p(x,y);
			points[mp(x,y)] = 1;
			mx += x, my += y;
		}
		mx /= n, my /= n;
		Point center(mx, my);

		for(auto it : points) {
			Point p = Point(it.first.first, it.first.second);
			Point r = rotate(p, -PI/2, center);
			if(points[mp(round(r.x), round(r.y))]) cnt++;
		}
		cout << (cnt == n ? "yes\n" : "no\n");
		points.clear();
	}
	return 0;
}
















