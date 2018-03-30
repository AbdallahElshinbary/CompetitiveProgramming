#include <bits/stdc++.h>

using namespace std;

struct Point{
    double x, y;
    Point(double x, double y):x(x), y(y){}

    Point():x(0), y(0){}
    //read and write
    void read(){
        scanf("%lf %lf", &x, &y);
    }
    void print(){
        printf("%.9lf %.9lf", x, y);
    }

    //operators
    Point& operator=(const Point& o){
        x = o.x;
        y = o.y;
        return *this;
    }

    Point& operator+=(const Point& o){
        x += o.x;
        y += o.y;
        return *this;
    }

    Point& operator-=(const Point& o){
        x -= o.x;
        y -= o.y;
        return *this;
    }

    Point& operator*=(double fact){
        x -= fact;
        y -= fact;
        return *this;
    }
    Point& operator/=(double fact){
        x /= fact;
        y /= fact;
        return *this;
    }
};

Point any;

//------------------------operators---------------------------
//minus
Point operator-(const Point &a){
    return Point(-a.x, -a.y);
}


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

//comparisons
bool operator==(const Point & a, const Point & b){
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Point & a, const Point & b){
    return a.x != b.x || a.y != b.y;
}


//---------------------functions----------------------

double angle(const Point& p){
    return atan2(p.y, p.x);
}

double angle(const Point& a, const Point& b){
    return atan2(a^b, a*b);
}

Point rotate(const Point &p, double an){
    return Point(p.x * sin(an) - p.y * cos(an), p.x * cos(an) + p.y * sin(an));
}

Point rotate(const Point &p, double an, Point& around){
    return rotate(p - around, an) + around;
}

double abs(const Point &p){
    return p*p;
}

double norm(const Point &p){
    return sqrt(p*p);
}



Point perp(const Point &p){
    return Point(-p.y, p.x);
}

Point bisector(const Point &a, const Point &b){
    return a * norm(b) + b * norm(a);
}
//projection
double proj(const Point &a, const Point &b){
    return a * b / norm(b);
}
//


//--------------------------------------lines------------------------------------------------


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


double dist(const Line& l, Point& p){
        return abs(((p-l.a)^l.ab)/norm(l.ab));
}

bool inter(const Line& s1, const Line &s2, Point& res){
    if((s1.ab ^ s2.ab) == 0)return 0; // parallel
    double t = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
    res = s1.a + s1.ab * t;
    return 1;
}

double proj(const Point &p, const Line &l, Point &res){
    res = l.a;
    res += l.ab *  ( ((p - l.a) * l.ab) / abs(l.ab) );
}
void reflection(const Point &p, const Line &l, Point &res){
    proj(p, l, res);
	res = 2 * res - p;
}

//-----------------------------segment----------------------------------



struct Segment{
    Point a, ab;
    Segment(const Point &a, const Point &b):a(a), ab(b-a){}
    Segment():a(), ab(){}

    Point b () const {
        return a + ab;
    }
};


bool onsegment(const Segment& r, const Point& p){
    return ((p - r.a) ^ r.ab) == 0 && ((p - r.a) * (p - r.b())) <= 0;
}



double dist(const Segment& r, const Point& p){
        if((p - r.a) * (r.ab) <= 0)return norm(p - r.a);
        if((p - r.b()) * (-r.ab) <= 0)return norm(p - r.b());

        return abs(((p-r.a)^r.ab)/norm(r.ab));
}



bool bet(const Segment &s1, const Segment &s2, const Point &p){
    return (dist(s1, p) + dist(s2, p) == dist(s2, s1.a));
}

bool inter(const Segment& s1, const Segment &s2, Point& res = any){
    if((s1.ab ^ s2.ab) == 0)return 0; // parallel
    double t1 = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
    double t2 = ((s1.a - s2.a) ^ s1.ab) / (s2.ab ^ s1.ab);
    if(t1 < 0 || t1 > 1 || t2 < 0 || t2 > 1)return 0;// does not intersect
    res = s1.a + s1.ab * t1;
    return 1;
}

//----------------------------------------------------------------------


int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);


	int n,l[4], r[4];
	cin >> n;
	while(n--) {
		cin >> l[0] >> l[1] >> l[2] >> l[3] >> r[0] >> r[1] >> r[2] >> r[3];

		if(r[0] > r[2])
			swap(r[0], r[2]);
		if(r[1] < r[3])
			swap(r[1], r[3]);

		Point ls(l[0], l[1]), le(l[2], l[3]), rtl(r[0], r[1]), rtr(r[2], r[1]), rbl(r[0], r[3]), rbr(r[2], r[3]);

		Segment L(ls, le), R1(rtl, rtr), R2(rtr, rbr), R3(rbr, rbl), R4(rbl, rtl);
		bool inside = (L.a.x >= rtl.x && L.a.y <= rtl.y && L.a.x <= rbr.x && L.a.y >= rbr.y) ||
					  (L.b().x >= rtl.x && L.b().y <= rtl.y && L.b().x <= rbr.x && L.b().y >= rbr.y);
		if(inter(L, R1) || inter(L, R2) || inter(L, R3) || inter(L, R4) || inside)
			cout << "T\n";
		else
			cout << "F\n";
	}

    return 0;
}

