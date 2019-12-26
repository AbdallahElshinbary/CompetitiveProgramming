#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class UnionFind {
    private:
    vector<int> p, rank;
    public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
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

double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
	int t,n,m,w,num;
	string x,y;
	map<string, int> mp;
	vector<pair<int, pair<int, int> > > EdgeList;

	cin >> t;
	while(t--) {
		num=1;
		UnionFind UF(2005);
		EdgeList.clear(); mp.clear();

		cin >> n >> m;
		for(int i=0; i<m; i++) {
			cin >> x >> y >> w;
			if(!mp[x]) mp[x] = num++;
			if(!mp[y]) mp[y] = num++;
			EdgeList.push_back(make_pair(w, make_pair(mp[x], mp[y])));
		}
		sort(EdgeList.begin(), EdgeList.end());

		int ans=0;
		for(auto e : EdgeList) {
			int w = e.first;
			int u = e.second.first, v = e.second.second;
			if(!UF.isSameSet(u, v)) {
				ans += w; UF.unionSet(u, v);
			}
		}
		cout << ans << "\n";
		if(t) cout << "\n";
	}

	return 0;
}
