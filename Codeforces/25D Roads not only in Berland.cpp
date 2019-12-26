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
    void unionSet(int i, int j) {
    	if (!isSameSet(i, j)) {
        	int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main() {
	int n,x,y,r;
	vector<ii> v;
	cin >> n;
	UnionFind uf(n+1);

	cin >> r >> y;
	uf.unionSet(r,y);

	for(int i=1; i<n-1; i++) {
		cin >> x >> y;
		if(!uf.isSameSet(x,y)) uf.unionSet(x,y);
		else v.push_back(ii(x,y));
	}

	printf("%d\n", v.size());
	for(int i=1; i<=n; i++) {
		if(!uf.isSameSet(i,r)) {
			uf.unionSet(i,r);
			printf("%d %d %d %d\n", v.back().first, v.back().second, i, r);
			v.pop_back();
		}
	}

	return 0;
}











