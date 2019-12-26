#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<16> MASK;

#define INF 1e9

int n,m,t=1,tx,ty;
pair<int, int> arr[16];
char c;
int dist[20][20];
int dp[1<<16][20];

int go(int mask, int last) {
	if(mask == (1 << t)-1) return dist[last][0];

	int &ret = dp[mask][last];
	if(ret != -1) return ret;
	ret = INF;

	for(int i=1; i<t; i++)
		if(!(mask & (1 << i))) ret = min(ret, dist[last][i] + go(mask | (1 << i), i));

	return ret;
}

int main() {
	while(cin >> n >> m) {
		t=1;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin >> c;
				if(c == 'L') arr[0] = {i,j};
				else if(c == '#') arr[t++] = {i,j};
			}
		}
		for(int i=0; i<t; i++)
			for(int j=0; j<t; j++)
				dist[i][j] = max(abs(arr[i].first-arr[j].first) , abs(arr[i].second-arr[j].second));

		memset(dp, -1, sizeof dp);
		cout << go(1, 0) << "\n";
	}

	return 0;
}
