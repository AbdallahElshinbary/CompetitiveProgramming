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
bool inter(const Segment& s1, const Segment &s2, Point& res){
    if((s1.ab ^ s2.ab) == 0) return 0; // parallel
    double t1 = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
    double t2 = ((s1.a - s2.a) ^ s1.ab) / (s2.ab ^ s1.ab);
    if(t1 < 0 || t1 > 1 || t2 < 0 || t2 > 1) return 0;// does not intersect
    res = s1.a + s1.ab * t1;
    return 1;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t,n,m;
	double x1,y1,x2,y2;
	Segment s, l[105];

	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> x1 >> y1 >> x2 >> y2;
			l[i] = Segment(Point(x1,y1), Point(x2,y2));
		}
		cin >> m;
		while(m--) {
			cin >> x1 >> y1;
			int idx=-1;
			while(1) {
				s = Segment(Point(x1, -INF), Point(x1, INF));
				double y=-1;
				bool ok=0;
				Point res;

				for(int i=0; i<n; i++) {
					if(inter(s, l[i], res)) {
						if(res.y < y1 && i != idx) {
							if(res.y > y) y = res.y, idx = i, ok=1;
						}
					}
				}
				if(!ok) {
					if(idx == -1) cout << x1 << "\n";
					else cout << (l[idx].a.y < l[idx].b().y ? l[idx].a.x : l[idx].b().x) << "\n";
					break;
				}
				if(l[idx].a.y < l[idx].b().y) x1 = l[idx].a.x, y1 = l[idx].a.y;
				else x1 = l[idx].b().x, y1 = l[idx].b().y;
			}
		}
		if(t) cout << "\n";
	}


	return 0;
}




















