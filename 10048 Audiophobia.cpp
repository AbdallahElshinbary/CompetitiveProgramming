#include <bits/stdc++.h>
using namespace std;

class UnioinFind {
private:
	vector<int> p, rank;
public:
	UnioinFind(int n) {
		p.assign(n+1, 0);
		rank.assign(n+1, 0);
		for(int i=0; i<=n; i++) p[i] = i;
	}
	int findSet(int i) {return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) {return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if(!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y])
				p[y] = x;
			else {
				p[x] = y;
				if(rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};

const int INF = 1e9;
vector<pair<int, pair<int,int> > > EdgeList;
vector<vector<pair<int,int> > > v;
int dist[105];

void bfs(int u) {
	queue<int> q;
	q.push(u);
	dist[u] = 0;
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		for(auto x : v[p]) {
			if(dist[x.first] == -1) {
				dist[x.first] = max(x.second, dist[p]);
				q.push(x.first);
			}
		}
	}
}

int main() {
	int n,m,q,x,y,z,t=0;
	while(cin >> n >> m >> q && (n || m || q)) {
		v.assign(n+1, {});
		while(m--) {
			cin >> x >> y >> z;
			EdgeList.push_back({z, {x,y}});
		}
		sort(EdgeList.begin(), EdgeList.end());

		UnioinFind UF(n);
		for(auto edge : EdgeList) {
			if(!UF.isSameSet(edge.second.first, edge.second.second)) {
				UF.unionSet(edge.second.first, edge.second.second);
				v[edge.second.first].push_back({edge.second.second, edge.first});
				v[edge.second.second].push_back({edge.second.first, edge.first});
			}
		}

		if(t) cout << "\n";
		cout << "Case #" << t+1 << "\n";
		while(q--) {
			cin >> x >> y;
			memset(dist, -1, sizeof dist);
			bfs(x);
			if(dist[y] == -1)
				cout << "no path\n";
			else
				cout << dist[y] << "\n";
		}

		EdgeList.clear();
		v.clear();
		t++;
	}
	return 0;
}

