#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

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

Point operator+(const Point &a, const Point &b){
    return Point(a.x+b.x, a.y+b.y);
}
Point operator-(const Point &a, const Point &b){
    return Point(a.x-b.x, a.y-b.y);
}
Point operator*(const double factor, const Point & p){
    return Point(factor * p.x, factor * p.y);
}
Point operator*(const Point & p, const double factor){
    return Point(factor * p.x, factor * p.y);
}
double operator^(const Point &a, const Point &b){
    return a.x*b.y - a.y*b.x;
}
bool operator==(const Point & a, const Point & b){
    return a.x == b.x && a.y == b.y;
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

	int t,n,a,b,x1,y1,x2,y2;
	Segment arr[15];
	int adj[15][15];
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> x1 >> y1 >> x2 >> y2;
			Point x(x1,y1), y(x2,y2);
			arr[i] = Segment(x,y);
		}

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				adj[i][j] = INF;

		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				if(inter(arr[i], arr[j]) || eq(arr[i], arr[j]))
					adj[i][j] = adj[j][i] = 1;

		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

		while(cin >> a >> b && a)
			cout << ((a == b || adj[a-1][b-1] != INF) ? "CONNECTED\n" : "NOT CONNECTED\n");
		if(t) cout << "\n";
	}

	return 0;
}
















