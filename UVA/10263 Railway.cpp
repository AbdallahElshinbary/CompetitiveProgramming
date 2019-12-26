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
    bool operator<(Point &o) const {
		if(fabs(x < o.x)) return y < o.y;
		return x < o.x;
	}
};

Point operator-(const Point &a){
    return Point(-a.x, -a.y);
}
Point operator+(const Point &a, const Point &b){
    return Point(a.x+b.x, a.y+b.y);
}
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

struct Line{
    Point a, ab;
    Line(const Point &a, const Point &b):a(a), ab(b-a){}
    Line():a(), ab(){}

    Point b(){
        return a + ab;
    }
};

struct Segment{
    Point a, ab;
    Segment(const Point &a, const Point &b):a(a), ab(b-a){}
    Segment():a(), ab(){}

    Point b () const {
        return a + ab;
    }
};

double abs(const Point &p){
    return p*p;
}
double norm(const Point &p){
    return sqrt(p*p);
}
double distPoint(Line &l, Point &p, Point &res) {
	//res = a + u * ab
	Point ap = p-l.a, ab = l.b()-l.a;
	double u = ap*ab / abs(ab);
	res = l.a + (ab*u);
    return abs(((p-l.a)^l.ab)/norm(l.ab));
}
double distPoint(Segment &r, Point &p, Point &res) {
    if((p - r.a) * (r.ab) <= 0) {res = r.a; return norm(p - r.a);}
    if((p - r.b()) * (-r.ab) <= 0) {res = r.b(); return norm(p - r.b());}

    Line l = Line(r.a, r.b());
    return distPoint(l, p, res);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	double x,y;
	while(cin >> x >> y) {
		Point M(x,y);
		cin >> n;
		Point arr[n+1];
		for(int i=0; i<=n; i++) {
			cin >> x >> y;
			arr[i] = Point(x,y);
		}
		Point temp, res;
		double tm, mn = 1e9;
		for(int i=0; i<n; i++) {
			Segment S(arr[i], arr[i+1]);
			tm = distPoint(S, M, temp);
			if(tm < mn)
				mn = tm, res = temp;
		}
		printf("%.4lf\n%.4lf\n", res.x, res.y);
	}

	return 0;
}
















