#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t,n,m,q,x,y;
int moves[41];
char c;
int dist[32770];

void bfs(int r) {
	queue<int> q; q.push(r); dist[r]=0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i=0; i<m; i++) {
			int v = u ^ moves[i];
			if(dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

int main() {
	cin >> t;
	for(int T=1; T<=t; T++) {
		memset(moves, 0, sizeof moves);

		cin >> n >> m;
		for(int i=0; i<m; i++) {
			cin >> x;
			while(x--) {cin >> y; moves[i] |= (1 << y);}
		}

		printf("Case %d:\n", T);
		memset(dist, -1, sizeof dist);
		bfs(0);

		cin >> q;
		while(q--) {
			x = 0;
			for(int i=n-1; i>=0; i--) {
				cin >> c;
				if(c == '1') x |= (1 << i);
			}
			printf("%d\n", dist[x]);
		}
		printf("\n");
	}

	return 0;
}

