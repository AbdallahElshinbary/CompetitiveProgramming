#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<double, double> ii;

#define INF 1e9
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s,x;
	double a,b;
	int t=1,d;
	map<string, ii> m = {
			{"N", {0,1}},
			{"S", {0,-1}},
			{"E", {1,0}},
			{"W", {-1,0}},
			{"NE", {1,1}},
			{"NW", {-1,1}},
			{"SE", {1,-1}},
			{"SW", {-1,-1}},
	};
	while(cin >> s && s != "END") {
		cin.ignore();
		stringstream ss(s);
		a=0, b=0;

		while(getline(ss, s, ',')) {
			stringstream xs(s);
			xs >> d >> x;
			if(x.back() == '.') x.pop_back();
			if(sz(x) == 1)
				a += d*m[x].first, b += d*m[x].second;
			else
				a += (d*m[x].first*1.0/sqrt(2)), b += (d*m[x].second*1.0/sqrt(2));
		}
		printf("Map #%d\n", t++);
		printf("The treasure is located at (%.3lf,%.3lf).\n", a,b);
		printf("The distance to the treasure is %.3lf.\n\n", hypot(a,b));
	}

	return 0;
}
















