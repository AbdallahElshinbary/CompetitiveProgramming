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
	void reset(int n) {
		rank.assign(n+1, 0);
		for(int i=0; i<=n; i++) p[i] = i;
	}
};

vector<pair<double, pair<int,int> > > EdgeList;
vector<int> used;

int main() {
	int t,n,m,x,y,z,cost,second_cost,temp;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i=0; i<m; i++) {
			cin >> x >> y >> z;
			EdgeList.push_back({z,{x,y}});
		}
		cost = 0;
		sort(EdgeList.begin(), EdgeList.end());

		UnioinFind UF(n);
		for(int i=0; i<(int)EdgeList.size(); i++) {
			auto edge = EdgeList[i];
			if(!UF.isSameSet(edge.second.first, edge.second.second)) {
				UF.unionSet(edge.second.first, edge.second.second);
				cost += edge.first;
				used.push_back(i);
			}
		}
		cout << cost << " ";

		second_cost = 1e9;
		for(int x : used) {
			UF.reset(n);
			temp = 0;
			for(int i=0; i<(int)EdgeList.size(); i++) {
				if(i == x)
					continue;
				auto edge = EdgeList[i];
				if(!UF.isSameSet(edge.second.first, edge.second.second)) {
					UF.unionSet(edge.second.first, edge.second.second);
					temp += edge.first;
				}
			}
			if(temp >= cost)
				second_cost = min(second_cost, temp);
		}
		cout << second_cost << "\n";

		EdgeList.clear();
		used.clear();
	}
	return 0;
}

