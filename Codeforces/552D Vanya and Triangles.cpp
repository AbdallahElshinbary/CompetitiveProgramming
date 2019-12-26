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
bool collinear(const Point &a, const Point &b, const Point &c) {
	return ((a.y-b.y)*(b.x-c.x)) == ((b.y-c.y)*(a.x-b.x));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,x,y;
	Point arr[2005];
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x >> y;
		arr[i] = Point(x,y);
	}

	ll ans = 0;
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			for(int k=j+1; k<n; k++)
				if(!collinear(arr[i], arr[j], arr[k]))
					ans++;
	cout << ans;

	return 0;
}




















