#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<double, double> ii;

#define INF 1e9
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

struct Line{
    Point a, ab;
    Line(const Point &a, const Point &b):a(a), ab(b-a){}
    Line():a(), ab(){}

    Point b(){
        return a + ab;
    }

};

bool online(const Line& l, Point& p){
    return ((p - l.a) ^ l.ab) == 0;
}

bool inter(const Line& s1, const Line &s2, Point& res){
    if((s1.ab ^ s2.ab) == 0)return 0; // parallel
    double t = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
    res = s1.a + s1.ab * t;
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,x1,y1,x2,y2;
	cin >> n;
	printf("INTERSECTING LINES OUTPUT\n");
	while(n--) {
		cin >> x1 >> y1 >> x2 >> y2;
		Point a(x1,y1), b(x2,y2);
		Line l1(a,b);
		cin >> x1 >> y1 >> x2 >> y2;
		Point c(x1,y1), d(x2,y2);
		Line l2(c,d);

		Point res;
		if(inter(l1,l2,res))
			printf("POINT %.2lf %.2lf\n", res.x, res.y);
		else {
			if(online(l1, c)) printf("LINE\n");
			else printf("NONE\n");
		}
	}
	printf("END OF OUTPUT\n");

	return 0;
}
















