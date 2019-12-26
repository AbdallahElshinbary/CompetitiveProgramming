#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class UnionFind {
    private:
    vector<int> p, rank;
    public:
    UnionFind(int N) {clr(N);}
    void clr(int N) {rank.assign(N, 0); p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;}
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            // rank keeps the tree short
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main() {
	int t,n,m,x,y,w,c,z;
	vector<pair<pair<int, int>, pair<int, int> > > EdgeList;
	vector<int> mst, ways;
	bool flag[205]{};

	cin >> t;
	for(int T=1; T<=t; T++) {
		cin >> n >> m;
		UnionFind UF(105);
		EdgeList.clear(); mst.clear(); ways.clear();
		memset(flag, 0, sizeof flag);

		for(int i=1; i<=m; i++) {
			cin >> x >> y >> w;
			EdgeList.push_back(make_pair(make_pair(w, i), make_pair(x, y)));
		}
		sort(EdgeList.begin(), EdgeList.end());

		c = z = 0;
		for(auto e : EdgeList) {
			int w = e.first.first, idx = e.first.second;
			int u = e.second.first, v = e.second.second;
			if(!UF.isSameSet(u, v)){
				mst.push_back(idx);
				c++, z += w, UF.unionSet(u, v);
			}
		}
		printf("Case #%d : ", T);
		if(c != n-1) {printf("No way\n"); continue;}

		for(int f : mst) {
			flag[f]=1;
			c = z = 0; UF.clr(105);
			for(auto e : EdgeList) {
				int w = e.first.first, idx = e.first.second;
				int u = e.second.first, v = e.second.second;
				if(!flag[idx] && !UF.isSameSet(u, v))
					c++, z += w, UF.unionSet(u, v);
			}
			if(c == n-1) ways.push_back(z);
			flag[f]=0;
		}

		sort(ways.begin(), ways.end());
		if(ways.empty()) printf("No second way\n");
		else printf("%d\n", ways[0]);
	}
	return 0;
}
