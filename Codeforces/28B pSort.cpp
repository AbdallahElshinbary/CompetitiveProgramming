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
	int n,l,r;
	int arr[105], fav[105];
	cin >> n;
	for(int i=1; i<=n; i++) cin >> arr[i];
	for(int i=1; i<=n; i++) cin >> fav[i];

	UnionFind uf(105);
	for(int i=1; i<=n; i++) {
		l = i-fav[i], r = i+fav[i];
		if(l >= 1) uf.unionSet(i, l);
		if(r <= n) uf.unionSet(i, r);
	}

	for(int i=1; i<=n; i++)
		if(!uf.isSameSet(i, arr[i])) {cout << "NO"; return 0;}
	cout << "YES";

	return 0;
}











