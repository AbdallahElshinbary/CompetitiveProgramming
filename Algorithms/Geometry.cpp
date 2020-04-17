struct Point{
    double x, y;
    Point(double x, double y):x(x), y(y) {}
    Point():x(0), y(0) {}

    //read and write
    void read() {
        scanf("%lf %lf", &x, &y);
    }
    void print() {
        printf("%.9lf %.9lf\n", x, y);
    }
    //operators
    Point& operator=(const Point& o) {
        x = o.x;
        y = o.y;
        return *this;
    }

    Point& operator+=(const Point& o) {
        x += o.x;
        y += o.y;
        return *this;
    }

    Point& operator-=(const Point& o) {
        x -= o.x;
        y -= o.y;
        return *this;
    }

    Point& operator*=(double fact) {
        x -= fact;
        y -= fact;
        return *this;
    }
    Point& operator/=(double fact) {
        x /= fact;
        y /= fact;
        return *this;
    }
    bool operator<(const Point &o) const {
        if(fabs(x-o.x) < EPS) return y < o.y;
        return x < o.x;
    }
};

//###############################################################################//

//minus
Point operator-(const Point &a) {
    return Point(-a.x, -a.y);
}
//addition
Point operator+(const Point &a, const Point &b) {
    return Point(a.x+b.x, a.y+b.y);
}
//subtraction
Point operator-(const Point &a, const Point &b) {
    return Point(a.x-b.x, a.y-b.y);
}
//multiplication
Point operator*(const Point & p, const double factor) {
    return Point(p.x * factor, p.y * factor);
}
//division
Point operator/(const Point & p, const double factor) {
    return Point(p.x / factor, p.y / factor);
}

//dot product
double operator*(const Point &a, const Point &b) {
    return a.x*b.x + a.y*b.y;
}
//cross product
double operator^(const Point &a, const Point &b) {
    return a.x*b.y - a.y*b.x;
}

//comparisons
bool operator==(const Point & a, const Point & b) {
    return (fabs(a.x-b.x) < EPS) && (fabs(a.y-b.y) < EPS);
}
bool operator!=(const Point & a, const Point & b) {
    return a.x != b.x || a.y != b.y;
}

//###############################################################################//

double dist(const Point &p1, const Point &p2) {
    return hypot(p1.x-p2.x, p1.y-p2.y);
}
double abs(const Point &p) {
    return p*p;
}
double norm(const Point &p) {
    return sqrt(p*p);
}

double angle(const Point& p) {
    return atan2(p.y, p.x);
}
double angle(const Point& pivot, const Point& a) {
    return atan2(a.y - pivot.y, a.x - pivot.x);
}
double angle(const Point& a, const Point& o, const Point& b) {
    Point oa = a-o, ob = b-o;
    return acos((oa*ob) / sqrt(abs(oa) * abs(ob))); 
}

//CCW (Rad)
Point rotate(const Point &p, double an) {
    return Point(p.x * cos(an) - p.y * sin(an), p.x * sin(an) + p.y * cos(an));
}
Point rotate(const Point &p, double an, Point& around) {
    return rotate(p - around, an) + around;
}

//perpendicular vector
Point perp(const Point &p) {
    return Point(-p.y, p.x);
}
Point bisector(const Point &a, const Point &b) {
    return a * norm(b) + b * norm(a);
}

//projection
double proj(const Point &a, const Point &b) {
    return a * b / norm(b);
}
//on the same line
bool collinear(const Point &a, const Point &b, const Point &c) {
    // check if c is between a & b (Special case)
    // if(!(min(a.x,b.x) <= c.x) || !(c.x <= max(a.x,b.x))) return 0;
	// if(!(min(a.y,b.y) <= c.y) || !(c.y <= max(a.y,b.y))) return 0;
	return ((a.y-b.y)*(b.x-c.x)) == ((b.y-c.y)*(a.x-b.x));
}
int orientation(const Point &a, const Point &b, const Point &c) {
	int res = (a.y-b.y)*(b.x-c.x) - (b.y-c.y)*(a.x-b.x);
	return (res == 0 ? 0 : (res > 0 ? 1 : 2));	//collinear / clock wise / counterclock wise
}
//ccw --> left to ab, cw --> right to ab
int ccw(const Point &a, const Point &b, const Point &c) {
	int res = (a.y-b.y)*(b.x-c.x) - (b.y-c.y)*(a.x-b.x);
	return (res > 0 ? 0 : 1);   //(res == 0 --> collinear)
}

//###############################################################################//

struct Line{
    Point a, ab;
    Line(const Point &a, const Point &b):a(a), ab(b-a) {}
    Line():a(), ab() {}

    Point b() const {
        return a + ab;
    }
};

bool online(const Line& l, Point& p) {
    return ((p - l.a) ^ l.ab) == 0;
}
double dist(const Line& l, Point& p) {
        return abs(((p-l.a)^l.ab)/norm(l.ab));
}
double distPoint(Line &l, Point &p, Point &res) {
	//res = a + u * ab
	Point ap = p-l.a, ab = l.b()-l.a;
	double u = ap*ab / abs(ab);
	res = l.a + (ab*u);
    return abs(((p-l.a)^l.ab)/norm(l.ab));
}
bool inter(const Line& s1, const Line &s2, Point& res) {
    if((s1.ab ^ s2.ab) == 0) return 0; // parallel
    double t = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
    res = s1.a + s1.ab * t;
    return 1;
}
void proj(const Point &p, const Line &l, Point &res) {
    res = l.a;
    res += l.ab *  ( ((p - l.a) * l.ab) / abs(l.ab) );
}
void reflection(const Point &p, const Line &l, Point &res) {
    proj(p, l, res);
	res = res*2 - p;
}

//###############################################################################//

struct Segment{
    Point a, ab;
    Segment(const Point &a, const Point &b):a(a), ab(b-a) {}
    Segment():a(), ab() {}

    Point b () const {
        return a + ab;
    }
};

bool onsegment(const Segment& r, const Point& p) {
    return ((p - r.a) ^ r.ab) == 0 && ((p - r.a) * (p - r.b())) <= 0;
}
double dist(const Segment& r, const Point& p) {
        if((p - r.a) * (r.ab) <= 0) return norm(p - r.a);
        if((p - r.b()) * (-r.ab) <= 0) return norm(p - r.b());

        return abs(((p-r.a)^r.ab)/norm(r.ab));
}
double distPoint(Segment &r, Point &p, Point &res) {
    if((p - r.a) * (r.ab) <= 0) {res = r.a; return norm(p - r.a);}
    if((p - r.b()) * (-r.ab) <= 0) {res = r.b(); return norm(p - r.b());}

    Line l = Line(r.a, r.b());
    return distPoint(l, p, res);
}
bool bet(const Segment &s1, const Segment &s2, const Point &p) {
    return (dist(s1, p) + dist(s2, p) == dist(s2, s1.a));
}
bool inter(const Segment& s1, const Segment &s2, Point& res) {
    if((s1.ab ^ s2.ab) == 0) return 0; // parallel
    double t1 = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
    double t2 = ((s1.a - s2.a) ^ s1.ab) / (s2.ab ^ s1.ab);
    if(t1 < 0 || t1 > 1 || t2 < 0 || t2 > 1) return 0;// does not intersect
    res = s1.a + s1.ab * t1;
    return 1;
}
//when parallel
bool inter(const Segment& s1, const Segment &s2) {
	return (collinear(s1.a,s1.b(),s2.a) || collinear(s1.a,s1.b(),s2.b()) ||
			collinear(s2.a,s2.b(),s1.a) || collinear(s2.a,s2.b(),s1.b()));
}

//###############################################################################//

line eq: y-y1 = m(x-x1) //m = (y1-y2)/(x1-x2)
         y = mx + c

using line eq:
point above line --> y0 > mx0 + c
point on the line --> y0 = mx0 + c
point below line --> y0 < mx0 + c

using cross-product:
A=(x1,y1), B=(x2,y2), P=(x,y)
d = (x−x1)(y2−y1)−(y−y1)(x2−x1) // (+ on side) (- the other side)

Center of Symmetry of Points = ((∑x / n), (∑y / n));

//###############################################################################//

Circles:

Arc length: (α / 360) * perimeter;
Sector Area: (α / 360) * Area;
chord Length: 2 * r * sin(α/2);

radius of N kissing circles inside a circle: R*sin(PI/N)/(sin(PI/N)+1);

bool inCircle(Point &c, Point &p, double r) {
    double d = (p.x-c.x)*(p.x-c.x) + (p.y-c.y)*(p.y-c.y);
    return (d < r*r || fabs(d - r*r) < EPS);
}

//Circle from 3 points (not collinear):
Point findCircle(const Point &a, const Point &b, const Point &c) {
    Point m1 = (b+a)/2, v1 = b-a, pv1 = Point(v1.y, -v1.x);
    Point m2 = (b+c)/2, v2 = b-c, pv2 = Point(v2.y, -v2.x);
    Point end1 = m1+pv1, end2 = m2+pv2, center;
    inter(Line(m1,end1), Line(m2,end2), center);
    return center;
}

//Welzl algo (smallest circle enclosing n points)
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

//Points of intersection 2 circles:
double d=sqrt((x2-x1)^2 + (y2-y1)^2)
double a=(r1^2-r2^2+d^2)/(2*d)
double h=sqrt(r1^2-a^2)
double x3=x1+a*(x2-x1)/d   
double y3=y1+a*(y2-y1)/d   
double x4=x3+h*(y2-y1)/d       // also x4=x3-h*(y2-y1)/d
double y4=y3-h*(x2-x1)/d       // also y4=y3+h*(x2-x1)/d


//###############################################################################//

Triangles:
//area A
//perimeter p
//semi-perimeter s

Triangle Area with 3 points: fabs((x1*(y2-y3) +  x2*(y3-y1) +  x3*(y1-y2)) / 2);
Triangle Area with 3 sides: sqrt(s * (s - a) * (s - b) * (s - c));  //s (semi-perimeter)
inner Cricle radius: A/s
outer Circle radius: a*b*c / (4*A)  //(a,b,c --> sides)
cos low: c^2 = a^2 + b^2 - 2*a*b*cos(γ)  //(γ --> opposite to c) 
sin low: a/sin(α) = b/sin(β) = c/sin(γ) = 2R    //(opposite angles/ R for circumcircle)

//center and radius of inner circle
bool innerCircle(Point p1, Point p2, Point p3, Point &center, double &r) {
    r = rInCircle(p1, p2, p3);  // A/s
    if (fabs(r) < EPS) return 0;    // no inCircle center
    
    line l1, l2;    // compute these two angle bisectors
    double ratio = dist(p1, p2) / dist(p1, p3);
    Point p = p2 + ((p3-p2) * (ratio / (1 + ratio)));
    l1 = Line(p1, p);
    
    ratio = dist(p2, p1) / dist(p2, p3);
    p = p1 + ((p3-p1) * (ratio / (1 + ratio)));
    l2 = Line(p2, p);

    inter(l1, l2, center);
    return 1;
}

//Point inside triangle
double cross(Point &o, Point &a, Point &b) {
    return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}
bool inTriangle(Point &a, Point &b, Point &c, Point &t) {
    return (cross(a, b, t)*cross(a, c, t) < EPS)
        && (cross(b, a, t)*cross(b, c, t) < EPS)
        && (cross(c, a, t)*cross(c, b, t) < EPS);
}
bool inTriangle(Point p) {
    double area = triangle_area(a, b, p);
    area += triangle_area(a, p, c);
    area += triangle_area(p, b, c);
    return (area <= orgArea + EPS) ? 1: 0;
}

//###############################################################################//

Rectangles:

//Rect --> bottom-left, top-right
//recatngles intersection area
int inter(vector<Rect> v) {
	int l=-INF, r=INF, b=-INF, t=INF;
	for(Rect R : v) l = max(l, R.a.x);
	for(Rect R : v) r = min(r, R.b.x);
	for(Rect R : v) b = max(b, R.a.y);
	for(Rect R : v) t = min(t, R.b.y);
	if(l >= r || b >= t) return 0;	//no intersection
    return (r-l)*(t-b);
}

Rectangle into 4 squares:   //(l --> square side)
l = max(x, min(w,h/4));
l = max(x, min(h,w/4));
l = max(x, min(w,h)/2);

//###############################################################################//

Polygon:

angle of regular polygon: (n-2)*180.0 / n
area of regular polygon: (l*l*n) / (4*tan(PI/n))    //(l --> side length)

//half the determinant or matrix of points
double polygonArea(vector<Point> &p) {
	double result = 0.0;
    p.push_back(p[0]);  //start = end
	for (int i = 0; i < (int)p.size()-1; i++)
        result += p[i]^p[i+1];  //cross product
    p.pop_back(); 
	return fabs(result) / 2.0;
}

//###############################################################################//

//O(n)
bool pointInPolygon(Point pt, const vector<Point> &p) {
	double sum = 0;
	for (int i = 0; i < sz(p)-1; i++) {
		if(collinear(p[i], p[i+1], pt)) return 1;   //with between

		if (ccw(pt, p[i], p[i+1]))
			sum += angle(p[i], pt, p[i+1]);
		else
			sum -= angle(p[i], pt, p[i+1]);
	}

	return fabs(fabs(sum) - 2*PI) < EPS;
}

//O(log(n))
#define Det(a,b,c) ((double)(b.x-a.x)*(double)(c.y-a.y)-(double)(b.y-a.y)*(c.x-a.x))
bool pointInConvex(Point pt, vector<Point>& p) {
    int a = 1, b = p.size()-1, c;
    if (Det(p[0], p[a], p[b]) > 0) swap(a,b);
    if (Det(p[0], p[a], pt) >= 0 || Det(p[0], p[b], pt) <= 0) return false;
    while(abs(a-b) > 1) {
        c = (a+b)/2;
        if (Det(p[0], p[c], pt) > 0) b = c; 
        else a = c;
    }
    return Det(p[a], p[b], pt) < 0;
}

//###############################################################################//

Point pivot(0,0);
bool angleCMP(Point &a, Point &b) {
	return angle(pivot, a) < angle(pivot, b);
}

vector<Point> ConvexHull(vector<Point> p) {
	if(sz(p) <= 1) return p;

	for(int i=0; i<sz(p); i++)
		if(Point(p[i].y, p[i].x) < Point(p[0].y, p[0].x))	//get bottom-most point
			swap(p[0], p[i]);

	pivot = p[0];
	sort(p.begin()+1, p.end(), angleCMP);

	vector<Point> ch;
	ch.push_back(p[0]), ch.push_back(p[1]);

    //Graham Scan
	for(int i=2; i<sz(p); i++) {
		while(sz(ch) > 1 && orientation(ch[sz(ch)-2], ch[sz(ch)-1], p[i]) == 1)	//clock wise
			ch.pop_back();
		ch.push_back(p[i]);
	}
	ch.push_back(ch[0]);	//close the polygon

	return ch;
}

//###############################################################################//
