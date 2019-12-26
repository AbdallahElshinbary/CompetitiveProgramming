#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

struct Point{
    double x, y;
    Point(double x, double y):x(x), y(y){}
    Point():x(0), y(0){}
};

//addition
Point operator+(const Point &a, const Point &b){
    return Point(a.x+b.x, a.y+b.y);
}
//subtraction
Point operator-(const Point &a, const Point &b){
    return Point(a.x-b.x, a.y-b.y);
}
//multiplication
Point operator*(const Point & p, const double factor){
    return Point(p.x * factor, p.y * factor);
}
//division
Point operator/(const Point & p, const double factor){
    return Point(p.x / factor, p.y / factor);
}
//dot product
double operator*(const Point &a, const Point &b){
    return a.x*b.x + a.y*b.y;
}
//cross product
double operator^(const Point &a, const Point &b){
    return a.x*b.y - a.y*b.x;
}

double dist(const Point &p1, const Point &p2) {
    return hypot(p1.x-p2.x, p1.y-p2.y);
}
bool collinear(const Point &a, const Point &b, const Point &c) {
	return ((a.y-b.y)*(b.x-c.x)) == ((b.y-c.y)*(a.x-b.x));
}

//###############################################################################//

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

Point findCircle(const Point &a, const Point &b, const Point &c) {
    Point m1 = (b+a)/2, v1 = b-a, pv1 = Point(v1.y, -v1.x);
    Point m2 = (b+c)/2, v2 = b-c, pv2 = Point(v2.y, -v2.x);
    Point end1 = m1+pv1, end2 = m2+pv2, center;
    inter(Line(m1,end1), Line(m2,end2), center);
    return center;
}

double smallestEnclosingCircle(Point p[], int n) {
    Point c = p[0];
    double r = 0.0;
    for(int i = 1; i < n; i++) {
        if(dist(p[i], c) >= r+EPS) {
            c = p[i], r = 0;
            for(int j = 0; j < i; j++) {
                if(dist(p[j], c) >= r+EPS) {
                    c.x = (p[i].x+p[j].x)/2;
                    c.y = (p[i].y+p[j].y)/2;
                    r = dist(p[i], c);
                    for(int k = 0; k < j; k++) {
                        if(dist(p[k], c) >= r+EPS) {
                            c = findCircle(p[i], p[j], p[k]);
                            r = dist(p[i], c);
                        }
                    }
                }
            }
        }
    }
    return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	double x,y,R,r;
		Point p[105];
		while(cin >> n && n) {
		for(int i=0; i<n; i++) {
			cin >> x >> y;
			p[i] = Point(x,y);
		}
		cin >> R;

		r = smallestEnclosingCircle(p, n);
		cout << (r > R ? "There is no way of packing that polygon.\n" : "The polygon can be packed in the circle.\n");
	}
}



















