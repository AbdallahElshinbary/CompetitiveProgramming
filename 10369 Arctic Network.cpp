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

vector<pair<double, pair<int,int> > > EdgeList;
vector<pair<int,int> > v;

int main() {
	int t,s,p,cc;
	double x,y,z,mm;
	cin >> t;
	while(t--) {
		cin >> s >> p;
		cc = p, mm = -1;
		for(int i=0; i<p; i++) {
			cin >> x >> y;
			v.push_back({x,y});
		}
		for(int i=0; i<p; i++) {
			for(int j=i+1; j<p; j++) {
				z = sqrt( (v[i].first-v[j].first)*(v[i].first-v[j].first) + (v[i].second-v[j].second)*(v[i].second-v[j].second) );
				EdgeList.push_back({z, {i,j}});
			}
		}
		sort(EdgeList.begin(), EdgeList.end());

		UnioinFind UF(p);
		for(auto edge : EdgeList) {
			if(!UF.isSameSet(edge.second.first, edge.second.second)) {
				UF.unionSet(edge.second.first, edge.second.second);
				mm = fmax(mm, edge.first);
				cc --;
			}
			if(cc == s)
				break;
		}

		cout << fixed << setprecision(2) << mm << "\n";

		EdgeList.clear();
		v.clear();
	}
	return 0;
}

