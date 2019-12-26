#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int x[1005], y[1005];
double dist[1005][1005];
double dp[1005][1005];

double getDist(int x1, int y1, int x2, int y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double go(int p1, int p2) {
	int v = 1 + max(p1, p2);
	if(v == n-1) return dist[p1][v] + dist[v][p2];

	if(dp[p1][p2] != -1) return dp[p1][p2];
	return dp[p1][p2] = min(dist[p1][v] + go(v,p2), dist[v][p2] + go(p1, v));
}

int main() {
	while(cin >> n) {
		for(int i=0; i<n; i++) cin >> x[i] >> y[i];
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				dist[i][j] = dist[j][i] = getDist(x[i],y[i],x[j],y[j]);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				dp[i][j] = -1;
		printf("%.2f\n", go(0,0));
	}

	return 0;
}
