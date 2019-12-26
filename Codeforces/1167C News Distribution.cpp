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
    int getRank(int i) {return rank[i];}
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

int cnt[500005], par[500005];

int main() {
	int n,m,k,x,y;
	cin >> n >> m;

	UnionFind UF(500005);

	for(int i=0; i<m; i++) {
		cin >> k;
		if(k) {cin >> x; k--;}
		while(k--) {
			cin >> y;
			UF.unionSet(x,y);
		}
	}

	for(int i=1; i<=n; i++) {
		par[i] = UF.findSet(i);
		cnt[par[i]]++;
	}

	for(int i=1; i<=n; i++) {
		cout << cnt[par[i]] << " ";
	}

	return 0;
}







