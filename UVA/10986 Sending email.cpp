#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int INF = 1e9;
vector<vector<ii> > AdjList;
vector<int> dist;

void SSSP(int s, int n) {
	dist.assign(n, INF);
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push({0,s});
	while(!pq.empty()) {
		ii x = pq.top();
		pq.pop();
		int d = x.first, u = x.second;
		if(d > dist[u])
			continue;
		for(auto v : AdjList[u]) {
			if(dist[u]+v.second < dist[v.first]) {
				dist[v.first] = dist[u]+v.second;
				pq.push({dist[v.first], v.first});
			}
		}
	}
}

int main() {
	int T,n,m,s,t,x,y,z;
	cin >> T;
	for(int i=1; i<=T; i++) {
		cin >> n >> m >> s >> t;
		AdjList.assign(n, {});
		while(m--) {
			cin >> x >> y >> z;
			AdjList[x].push_back({y,z});
			AdjList[y].push_back({x,z});
		}
		SSSP(s,n);
		cout << "Case #" << i << ": ";
		if(dist[t] == INF)
			cout << "unreachable\n";
		else
			cout << dist[t] << "\n";
	}

	return 0;
}

