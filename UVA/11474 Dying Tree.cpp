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

double dist(ii a, ii b) {
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main() {
	int t,n,m,b,x,y;
	double k,d;
	ii doc[12];
	vector<vector<ii> > v;

	cin >> t;
	while(t--) {
		cin >> n >> m >> k >> d;
		UnionFind uf(n);
		v.assign(n, {});

		for(int i=0; i<m; i++) cin >> doc[i].first >> doc[i].second;
		for(int i=0; i<n; i++) {
			cin >> b;
			while(b--) {cin >> x >> y; v[i].push_back(ii(x,y));}
		}
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				for(auto a : v[i])
					for(auto b : v[j]) {
						if(dist(a,b) <= k) {uf.unionSet(i,j); break;}
					}

		bool ok=0;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				for(auto a : v[j])
					if(dist(a, doc[i]) <= d && uf.isSameSet(0,j)) {ok=1; break;}
				if(ok) break;
			}
			if(ok) break;
		}

		cout << (ok ? "Tree can be saved :)\n" : "Tree can't be saved :(\n");
	}


	return 0;
}











