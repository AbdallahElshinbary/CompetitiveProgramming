#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e9
#define EPS 1e-9
#define PI 3.14159265359
#define mp make_pair
#define sz(s) (int)s.size()

double dist(int x1, int y1, int x2, int y2) {
	return hypot(x1-x2, y1-y2);
}

int solve(int a, int b, int c) {
	int s = 1, e = 1000, t, z, ans;
	while(s <= e) {
		t = (s+e)/2;
		z = a*(t*t) + b*(t) + c;
		if(z <= 0) {
			ans = t, e = t-1;
		} else {
			if(a < b) s = t+1;
			else e = t-1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N,B,a,b,c,d,e,f,g,t,x,y;
	pair<ii, int> players[22];
	string ans;

	scanf("PLAYERS=%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d %d\n", &players[i].first.first, &players[i].first.second, &players[i].second);
	scanf("BALLS=%d\n", &B);

	for(int i=1; i<=B; i++) {
		scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
		t = solve(a,b,c);
		x = d*t + e;
		y = f*t + g;
		if(x < 0 || y < 0) ans = "foul";
		else {
			bool caught = 0;
			for(int i=0; i<N; i++) {
				if(dist(x, y, players[i].first.first, players[i].first.second) / players[i].second < t)
					{ans = "caught", caught=1; break;}
			}
			if(!caught) ans = "safe";
		}
		printf("Ball %d was %s at (%d,%d)\n", i, ans.c_str(), x, y);
	}

	return 0;
}
















