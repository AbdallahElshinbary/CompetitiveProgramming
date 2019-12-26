#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int t=1,l,u,r;
int arr[12];
vector<int> dist;

void bfs(int s) {
	queue<int> q;
	q.push(s); dist[s]=0;
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int i=0; i<r; i++) {
			int x = (v+arr[i])%10000;
			if(dist[x] == INF) {
				dist[x] = dist[v]+1;
				if(x == u) return;
				q.push(x);
			}
		}
	}
}

int main() {
	while(cin >> l >> u >> r && r) {
		for(int i=0; i<r; i++) cin >> arr[i];
		dist.assign(10005, INF);
		bfs(l);
		printf("Case %d: ", t++);
		if(dist[u] != INF) printf("%d\n", dist[u]);
		else printf("Permanently Locked\n");
	}


	return 0;
}
