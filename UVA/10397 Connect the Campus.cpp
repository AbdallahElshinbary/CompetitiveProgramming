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
	int n,m,a,b;
	int cx[800], cy[800];
	vector<pair<double, pair<int, int> > > EdgeList;

	while(cin >> n) {
		UnionFind UF(800);
		EdgeList.clear();

		for(int i=1; i<=n; i++)
			cin >> cx[i] >> cy[i];
		cin >> m;
		for(int i=0; i<m; i++) {
			cin >> a >> b;
			UF.unionSet(a, b);
		}
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				EdgeList.push_back(make_pair(dist(cx[i], cy[i], cx[j], cy[j]), make_pair(i, j)));
		sort(EdgeList.begin(), EdgeList.end());

		double ans=0;
		for(auto e : EdgeList) {
			double w = e.first;
			int u = e.second.first, v = e.second.second;
			if(!UF.isSameSet(u, v)) {
				ans += w; UF.unionSet(u, v);
			}
		}
		printf("%.2f\n", ans);
	}

	return 0;
}
