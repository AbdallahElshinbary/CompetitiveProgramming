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
};

struct Circle {
	Point c;
	double r;
	Circle(Point c, double r) : c(c), r(r) {}

	int check(Point p) {
	    double d = (p.x-c.x)*(p.x-c.x) + (p.y-c.y)*(p.y-c.y);
	    if(fabs(d - r*r) < EPS) return 1;
	    return (d < r*r ? 0 : 2);
	}

};

struct Rect {
	Point ll,lr,ul,ur;
	double l;
	Rect(Point ll, double l) : ll(ll), l(l) {
		lr = Point(ll.x+l, ll.y);
		ul = Point(ll.x, ll.y+l);
		ur = Point(ll.x+l, ll.y+l);
	}

	int check(Point p) {
		if(p.x == ll.x && ll.y <= p.y && p.y <= ul.y) return 1;
		if(p.x == lr.x && lr.y <= p.y && p.y <= ur.y) return 1;
		if(p.y == ll.y && ll.x <= p.x && p.x <= lr.x) return 1;
		if(p.y == ul.y && ul.x <= p.x && p.x <= ur.x) return 1;
		return (ll.x < p.x && p.x < lr.x && lr.y < p.y && p.y < ur.y) ? 0 : 2;
	}
};

struct Color {
	int r,g,b;
	Color(int r, int g, int b) : r(r), g(g), b(b) {}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t,n,m,x,y,l,r,g,b;
	string type;
	cin >> t;
	for(int T=1; T<=t; T++) {
		cin >> n >> m;
		vector<Circle> cir;
		vector<Rect> rec;
		vector<Color> cc, rc;
		while(n--) {
			cin >> type >> x >> y >> l >> r >> g >> b;
			if(type == "CIRCLE")
				cir.push_back(Circle(Point(x,y), l)), cc.push_back(Color(r,g,b));
			else
				rec.push_back(Rect(Point(x,y), l)), rc.push_back(Color(r,g,b));
		}

		double ar=0, ag=0, ab=0;
		int cnt, res;
		bool border;
		printf("Case %d:\n", T);

		while(m--) {
			cin >> x >> y;
			ar=ag=ab=cnt=res=border=0;
			for(int i=0; i<sz(cir); i++) {
				res = cir[i].check(Point(x,y));
				if(res == 0) cnt++, ar += cc[i].r, ag += cc[i].g, ab += cc[i].b;
				else if(res == 1) {border=1; break;}
			}
			if(border) {printf("(0, 0, 0)\n"); continue;}

			for(int i=0; i<sz(rec); i++) {
				res = rec[i].check(Point(x,y));
				if(res == 0) cnt++, ar += rc[i].r, ag += rc[i].g, ab += rc[i].b;
				else if(res == 1) {border=1; break;}
			}
			if(border) {printf("(0, 0, 0)\n"); continue;}

			if(cnt == 0) {printf("(255, 255, 255)\n"); continue;}
			printf("(%d, %d, %d)\n", (int)round(ar*1.0/cnt), (int)round(ag*1.0/cnt), (int)round(ab*1.0/cnt));
		}

		if(T<t) printf("\n");
	}

	return 0;
}




















