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

int main() {
	int t,n,w;
	char c;
	vector<pair<int, pair<int, int> > > EdgeList;

	cin >> t;
	for(int T=1; T<=t; T++) {
		UnionFind UF(30);
		EdgeList.clear();

		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> w;
			if(w) if(w) EdgeList.push_back(make_pair(w, make_pair(i, 0)));
			for(int j=1; j<n; j++) {
				cin >> c >> w;
				if(w) EdgeList.push_back(make_pair(w, make_pair(i, j)));
			}
		}
		sort(EdgeList.begin(), EdgeList.end());

		printf("Case %d:\n", T);
		for(auto e : EdgeList) {
			int w = e.first;
			int u = e.second.first, v = e.second.second;
			if(!UF.isSameSet(u, v)) {
				printf("%c-%c %d\n", 'A'+u, 'A'+v, w);
				UF.unionSet(u, v);
			}
		}
	}

	return 0;
}
