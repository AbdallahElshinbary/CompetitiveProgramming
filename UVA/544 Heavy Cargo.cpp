#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<pair<int, int> > > adj;
map<string, int> mp;
priority_queue<pair<int, int> > pq;
bool vis[205];

void go(int u) {
	vis[u] = 1;
	for(auto x : adj[u])
		if(!vis[x.first]) pq.push(make_pair(x.second, -x.first));
}

int main() {
	int n,r,w,num,mn,t=1;
	string x,y;

	while(cin >> n >> r && n) {
		mp.clear();
		adj.assign(205, {});
		num=1, mn=1e9;
		memset(vis, 0, sizeof vis);

		for(int i=0; i<r; i++) {
			cin >> x >> y >> w;
			if(!mp[x]) mp[x] = num++;
			if(!mp[y]) mp[y] = num++;
			adj[mp[x]].push_back(make_pair(mp[y], w));
			adj[mp[y]].push_back(make_pair(mp[x], w));
		}
		cin >> x >> y;
		go(mp[x]);

		while(!pq.empty()) {
			auto front = pq.top(); pq.pop();
			int w = front.first, u = -front.second;
			if(!vis[u]) {
				mn=min(mn, w);
				if(u == mp[y]) break;
				go(u);
			}
		}
		while(!pq.empty()) pq.pop();

		printf("Scenario #%d\n%d tons\n\n", t++, mn);
	}

	return 0;
}
