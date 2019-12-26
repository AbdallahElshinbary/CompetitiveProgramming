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
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main() {
	int t=1,n,m,a,b,ans;
	bool done[50005];
	while(cin >> n >> m && n) {
		UnionFind uf(n+1); ans=0;
		memset(done, 0, sizeof done);
		while(m--) {cin >> a >> b; uf.unionSet(a, b);}
		for(int i=1; i<=n; i++) if(!done[uf.findSet(i)]) done[uf.findSet(i)]=1, ans++;
		printf("Case %d: %d\n", t++, ans);
	}

	return 0;
}











