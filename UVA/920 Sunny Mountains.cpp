#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e9
#define EPS 1e-9
#define PI 3.14159265359
#define mp make_pair
#define sz(s) (int)s.size()

struct Point {
	double x,y;
	Point() : x(0), y(0) {}
	Point(double x, double y) : x(x), y(y) {}
    bool operator<(Point &o) const {
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

double dist(Point &a, Point &b) {
	return hypot(a.x-b.x, a.y-b.y);
}
double abs(const Point &p){
    return p*p;
}
double norm(const Point &p){
    return sqrt(p*p);
}
struct Line{
    Point a, ab;
    Line(const Point &a, const Point &b):a(a), ab(b-a){}
    Line():a(), ab(){}
    Point b(){
        return a + ab;
    }
};
bool inter(const Line& s1, const Line &s2, Point& res){
    if((s1.ab ^ s2.ab) == 0) return 0; // parallel
    double t = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
    res = s1.a + s1.ab * t;
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t,n;
	double x,y;
	Point arr[105];
	Point in;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> x >> y;
			arr[i] = Point(x,y);
		}
		sort(arr, arr+n);

		int cur = n-1;
		double ans = 0;
		for(int i=n-2; i>=0; i--) {
			if(arr[i].y > arr[cur].y) {
				if(cur == i-1)	ans += dist(arr[i], arr[cur]);
				else {
					Line l1(arr[i], arr[i+1]);
					Point org(0, arr[cur].y);
					Line l2(org, arr[cur]);
					inter(l1, l2, in);
					ans += dist(arr[i], in);
				}
				cur = i;
			}
		}
		cout << fixed << setprecision(2) << ans << "\n";
	}

	return 0;
}




















