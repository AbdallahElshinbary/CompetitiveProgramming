#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int x[1005], y[1005], p[1005];
double dp[1005][1005];

double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double go(int idx, int prev) {
	if(idx > n) return dist(x[prev], y[prev], 100, 100) + 1;

	double &ret = dp[prev][idx];
	if(ret != -1) return ret;
	ret = min(dist(x[prev],y[prev],x[idx],y[idx]) + 1 + go(idx+1, idx), p[idx] + go(idx+1, prev));
	return ret;
}

int main() {
	while(cin >> n && n) {
		x[0] = 0, y[0] = 0;
		for(int i=1; i<=n; i++) cin >> x[i] >> y[i] >> p[i];

		for(int i=0; i<1005; i++)
			for(int j=0; j<1005; j++)
				dp[i][j] = -1;

		printf("%.3f\n", go(1, 0));
	}

	return 0;
}
