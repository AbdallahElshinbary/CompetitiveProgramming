#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e9
#define EPS 1e-9
#define PI 3.14159265359
#define mp make_pair
#define sz(s) (int)s.size()

struct Point {
	int x,y;
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
	bool operator<(const Point &o) const {
		return ((x == o.x) ? (y < o.y) : (x < o.x));
	}
};

bool collinear(const Point &a, const Point &b, const Point &c) {
	return ((a.y-b.y)*(b.x-c.x)) == ((b.y-c.y)*(a.x-b.x));
}

int flag[305][305];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,x,y,cnt;
	Point arr[305];
	while(1) {
		n = 0;
		while(scanf("%d %d", &x, &y) && (x+y)) {
			arr[n] = Point(x,y);
			n++;
		}
		if(!n) break;
		sort(arr, arr+n);

		cnt = 0;
		memset(flag, -1, sizeof flag);
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				for(int k=j+1; k<n; k++)
				if(collinear(arr[i], arr[j], arr[k])) {
					if(flag[i][j] == -1) flag[i][j] = cnt++;
					flag[i][k] = flag[j][k] = flag[i][j];
				}
			}
		}


		if(cnt == 0) {
			printf("No lines were found\n");
			continue;
		}
		printf("The following lines were found:\n");

		set<int> s;
		for(int i=0; i<cnt; i++) {
			for(int j=0; j<n; j++)
				for(int k=j+1; k<n; k++)
					if(flag[j][k] == i)
						s.insert(j), s.insert(k);
			for(int x : s) printf("(%4d,%4d)", arr[x].x, arr[x].y);
			printf("\n");
			s.clear();
		}
	}

	return 0;
}










