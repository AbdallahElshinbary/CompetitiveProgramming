#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e12
#define EPS 1e-9
#define PI 3.14159265359
#define mp make_pair
#define sz(s) (int)s.size()

struct Point{
    double x, y;
    Point(double x, double y):x(x), y(y){}
    Point():x(0), y(0){}
    bool operator<(const Point &o) const {
        if(fabs(x-o.x) < EPS) return y < o.y;
        return x < o.x;
    }
};
Point operator+(const Point &a, const Point &b){
    return Point(a.x+b.x, a.y+b.y);
}
Point operator-(const Point &a, const Point &b){
    return Point(a.x-b.x, a.y-b.y);
}
double operator*(const Point &a, const Point &b){
    return a.x*b.x + a.y*b.y;
}
double operator^(const Point &a, const Point &b){
    return a.x*b.y - a.y*b.x;
}
Point operator*(const double factor, const Point & p){
    return Point(factor * p.x, factor * p.y);
}
Point operator*(const Point & p, const double factor){
    return Point(factor * p.x, factor * p.y);
}
bool operator==(const Point & a, const Point & b){
    return fabs(a.x-b.x) < EPS && fabs(a.y-b.y) < EPS;
}

struct Segment{
    Point a, ab;
    Segment(const Point &a, const Point &b):a(a), ab(b-a){}
    Segment():a(), ab(){}

    Point b () const {
        return a + ab;
    }
};
bool inter(const Segment& s1, const Segment &s2){
    if((s1.ab ^ s2.ab) == 0) return 0; // parallel
    double t1 = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
    double t2 = ((s1.a - s2.a) ^ s1.ab) / (s2.ab ^ s1.ab);
    if(t1 < 0 || t1 > 1 || t2 < 0 || t2 > 1) return 0;// does not intersect
    return 1;
}
bool collinear(const Point a, const Point b, const Point c) {
	if(!(min(a.x,b.x) <= c.x) || !(c.x <= max(a.x,b.x))) return 0;
	if(!(min(a.y,b.y) <= c.y) || !(c.y <= max(a.y,b.y))) return 0;
	return (((a.y-b.y)*(c.x-b.x)) == ((c.y-b.y)*(a.x-b.x)));
}

bool eq(const Segment& s1, const Segment &s2){
	return (collinear(s1.a,s1.b(),s2.a) || collinear(s1.a,s1.b(),s2.b()) ||
			collinear(s2.a,s2.b(),s1.a) || collinear(s2.a,s2.b(),s1.b()));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t,n;
	double x1,y1,x2,y2;
	double r[105];
	Segment arr[105];
	vector<Point> v;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> x1 >> y1 >> x2 >> y2 >> r[i];
			arr[i] = Segment(Point(x1,0), Point(x2,0));
			v.push_back(Point(x1,0));
			v.push_back(Point(x2,0));
		}
		sort(v.begin(), v.end());

		Segment s;
		double x;
		printf("%d\n", sz(v)+1);
		printf("-inf %.3lf 1.000\n", v[0].x);
		for(int i=0; i<sz(v)-1; i++) {
			x = 1;
			s = Segment(v[i], v[i+1]);
			for(int j=0; j<n; j++) {
				if(min(arr[j].a, arr[j].b()) == v[i+1]) continue;
				if(max(arr[j].a, arr[j].b()) == v[i]) continue;
				if(eq(s, arr[j])) x *= r[j];
			}
			printf("%.3lf %.3lf %.3lf\n", v[i].x, v[i+1].x, x);
		}
		printf("%.3lf +inf 1.000\n", v.back().x);
		if(t) printf("\n");
		v.clear();
	}

	return 0;
}




















