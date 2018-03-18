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

vector<pair<int, pair<int,int> > > EdgeList;

int main() {
	int t=0,n,m,k,x,y,z,cost=0;
	while(cin >> n) {
		for(int i=1; i<n; i++) {
			cin >> x >> y >> z;
			EdgeList.push_back({z, {x,y}});
			cost += z;
		}
		if(t) cout << "\n";
		cout << cost << "\n";
		cin >> k;
		while(k--) {
			cin >> x >> y >> z;
			EdgeList.push_back({z, {x,y}});
		}
		cin >> m;
		while(m--) {
			cin >> x >> y >> z;
			EdgeList.push_back({z, {x,y}});
		}
		sort(EdgeList.begin(), EdgeList.end());
		cost = 0;

		UnioinFind UF(n);
		for(auto edge : EdgeList) {
			if(!UF.isSameSet(edge.second.first, edge.second.second)) {
				cost += edge.first;
				UF.unionSet(edge.second.first, edge.second.second);
			}
		}
		cout << cost << "\n";
		cost = 0;
		EdgeList.clear();
		t++;
	}
	return 0;
}

