#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

class UnionFind {
    private:
    vector<int> p, rank;
    public:
    UnionFind(int N) {
        rank.assign(N, 1);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    int unionSet(int i, int j) {
    	int x = findSet(i), y = findSet(j);
    	if (x != y) {
            if (rank[x] > rank[y]) {
            	p[y] = x;
            	rank[x] += rank[y];
            	return rank[x];
            }
            else {
                p[x] = y;
                rank[y] += rank[x];
                return rank[y];
            }
        }
    	return rank[x];
    }
};

int main() {
	int t,n,m,a,b,ans;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		UnionFind uf(n+1); ans=1;
		while(m--) {cin >> a >> b; ans = max(ans, uf.unionSet(a,b));}
		cout << ans << "\n";
	}

	return 0;
}











