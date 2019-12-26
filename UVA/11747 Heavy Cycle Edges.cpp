#include <bits/stdc++.h>
using namespace std;

class UnioinFind {
private:
	vector<int> p, rank;
public:
	UnioinFind(int n) {
		p.assign(n, 0);
		rank.assign(n, 0);
		for(int i=0; i<n; i++) p[i] = i;
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
set<int> ss;

int main() {
	int n,m,x,y,z;
	while(cin >> n >> m && (n || m)) {
		for(int i=0; i<m; i++) {
			cin >> x >> y >> z;
			EdgeList.push_back({z, {x,y}});
		}
		sort(EdgeList.begin(), EdgeList.end());

		UnioinFind UF(n);
		for(auto edge : EdgeList) {
			if(!UF.isSameSet(edge.second.first, edge.second.second))
				UF.unionSet(edge.second.first, edge.second.second);
			else
				ss.insert(edge.first);
		}

		if(ss.empty())
			cout << "forest\n";
		else {
			auto it = ss.begin();
			cout << *it;
			it++;
			for(; it != ss.end(); it++)
				cout << " " << *it;
			cout << "\n";
		}

		EdgeList.clear();
		ss.clear();
	}
	return 0;
}

