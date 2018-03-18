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
map<string, int> mp;

int main() {
	int t,n,m,z,idx,cost;
	string x,y;
	cin >> t;
	while(t--) {
		cin >> m >> n;
		idx = cost = 0;
		for(int i=0; i<n; i++) {
			cin >> x >> y >> z;
			if(mp[x] == 0)
				mp[x] = ++idx;
			if(mp[y] == 0)
				mp[y] = ++idx;
			EdgeList.push_back({z, {mp[x],mp[y]}});
		}
		sort(EdgeList.begin(), EdgeList.end());

		UnioinFind UF(n);
		for(auto edge : EdgeList) {
			if(!UF.isSameSet(edge.second.first, edge.second.second)) {
				cost += edge.first;
				UF.unionSet(edge.second.first, edge.second.second);
			}
		}
		cout << cost << "\n";
		if(t)
			cout << "\n";
		mp.clear();
		EdgeList.clear();
	}
	return 0;
}

