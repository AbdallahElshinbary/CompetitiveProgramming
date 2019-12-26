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
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	double x1,y1,x2,y2;
	Segment arr[100005];

	while(cin >> n && n) {
		for(int i=0; i<n; i++) {
			cin >> x1 >> y1 >> x2 >> y2;
			arr[i] = Segment(Point(x1,y1), Point(x2,y2));
		}

		bool ok;
		vector<int> v;
		for(int i=0; i<n; i++) {
			ok = 1;
			for(int j=i+1; j<n; j++)
				if(inter(arr[i], arr[j]))
					{ok=0; break;}
			if(ok) v.push_back(i+1);
		}

		cout << "Top sticks: ";
		for(int i=0; i<sz(v)-1; i++) cout << v[i] << ", ";
		cout << v.back() << ".\n";
	}


	return 0;
}











