#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-9
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

#define Det(a,b,c) ((double)(b.x-a.x)*(double)(c.y-a.y)-(double)(b.y-a.y)*(c.x-a.x))
bool pointInConvex(Point pt, vector<Point>& p){
    int a = 1, b = p.size()-1, c;
    if (Det(p[0], p[a], p[b]) > 0) swap(a,b);
    if (Det(p[0], p[a], pt) >= 0 || Det(p[0], p[b], pt) <= 0) return false;
    while(abs(a-b) > 1) {
        c = (a+b)/2;
        if (Det(p[0], p[c], pt) > 0) b = c; else a = c;
    }
    return Det(p[a], p[b], pt) < 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m,x,y;
	vector<Point> v;
	cin >> n;
	while(n--) {
		cin >> x >> y;
		v.push_back(Point(x,y));
	}
	v.push_back(v.back());

	cin >> m;
	while(m--) {
		cin >> x >> y;
		if(!pointInConvex(Point(x,y), v)) {cout << "NO"; return 0;}
	}
	cout << "YES";
}



















