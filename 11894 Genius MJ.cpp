#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-4

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
    return a.x - b.x < EPS && a.y - b.y < EPS;
}

bool operator!=(const Point & a, const Point & b){
    return fabs(a.x - b.x) > EPS || fabs(a.y - b.y) > EPS;
}


//---------------------functions----------------------

double angle(const Point& p){
    return atan2(p.y, p.x);
}

double angle(const Point& a, const Point& b){
    return atan2(a^b, a*b);
}

Point rotate(const Point &p, double an){
    return Point(p.x * cos(an) - p.y * sin(an), p.x * sin(an) + p.y * cos(an));
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


Point arr1[100005];
Point arr2[100005];

bool cmp(Point &p1, Point &p2) {
	if(p1.x == p2.x)
		return p1.y < p2.y;
	else
		return p1.x < p2.x;
}

bool eq(Point arr1[], Point arr2[], int n) {
	for(int i=0; i<n; i++)
		if(arr1[i] != arr2[i])
			return false;
	return true;
}

void rot(Point arr[], int n, double an, Point &center) {
	for(int i=0; i<n; i++)
		arr[i] = rotate(arr[i], an, center);
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);


	int t,n;
	double x,y, mnx1, mny1, mnx2, mny2, mx1, my1, mx2, my2,tx,ty;
	cin >> t;
	while(t--) {
		mx1 = my1 = mx2 = my2 = -1e9;
		mnx1 = mny1 = mnx2 = mny2 = 1e9;
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> x >> y;
			mx1 = fmax(mx1, x), my1 = fmax(my1, y);
			mnx1 = fmin(mnx1, x), mny1 = fmin(mny1, y);
			arr1[i] = Point(x,y);
		}
		for(int i=0; i<n; i++) {
			cin >> x >> y;
			mx2 = fmax(mx2, x), my2 = fmax(my2, y);
			mnx2 = fmin(mnx2, x), mny2 = fmin(mny2, y);
			arr2[i] = Point(x,y);
		}

		Point c1((mnx1+mx1)/2, (mny1+my1)/2);
		Point c2((mnx2+mx2)/2, (mny2+my2)/2);
		Point c3(c1.x, c2.y);

		tx = norm(c2-c3);
		ty = norm(c1-c3);

		if(c1.x < c2.x) tx *= -1;
		if(c1.y < c2.y) ty *= -1;

		for(int i=0; i<n; i++)
			arr2[i] = Point(arr2[i].x+tx, arr2[i].y+ty);

		sort(arr1, arr1+n, cmp);
		sort(arr2, arr2+n, cmp);


		if(eq(arr1, arr2, n)) {
			cout << "MATCHED\n"; continue;
		} else rot(arr2, n, M_PI/2, c1);
		sort(arr2, arr2+n, cmp);

		if(eq(arr1, arr2, n)) {
			cout << "MATCHED\n"; continue;
		} else rot(arr2, n, M_PI/2, c1);
		sort(arr2, arr2+n, cmp);

		if(eq(arr1, arr2, n)) {
			cout << "MATCHED\n"; continue;
		} else rot(arr2, n, M_PI/2, c1);
		sort(arr2, arr2+n, cmp);


		if(eq(arr1, arr2, n)) cout << "MATCHED\n";
		else cout << "NOT MATCHED\n";
	}

	return 0;
}

