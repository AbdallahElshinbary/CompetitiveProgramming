#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

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
	int n,m,k,x,p,ans;
	while(cin >> n >> m && n) {
		UnionFind uf(n);
		while(m--) {
			cin >> k; p=-1;
			while(k--) {
				cin >> x;
				if(p != -1) uf.unionSet(x,p);
				p=x;
			}
		}

		ans=1;
		for(int i=1; i<n; i++) if(uf.isSameSet(0,i)) ans++;
		cout << ans << "\n";
	}

	return 0;
}











