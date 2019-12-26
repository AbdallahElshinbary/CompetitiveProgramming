#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 100005;

vector<vector<pair<int, int> > > adj;
int tree[6*MAX_N];
int E[6*MAX_N], L[6*MAX_N], H[MAX_N];
ll dist[MAX_N];
int idx;

//segment tree
void build(int node, int start, int end) {
	if(start == end) {
		tree[node] = start;
	} else {
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		int p1 = tree[2*node], p2 = tree[2*node+1];
		tree[node] = (L[p1] <= L[p2]) ? p1 : p2;
	}
}

int query(int node, int start, int end, int l, int r) {
	if(r < start || l > end) {
		return -1;
	} else if(l <= start && end <= r) {
		return tree[node];
	} else {
		int mid = (start + end) / 2;
		int p1 = query(2*node, start, mid, l, r);
		int p2 = query(2*node+1, mid+1, end, l, r);

		if(p1 == -1) return p2;
		if(p2 == -1) return p1;
		return (L[p1] <= L[p2]) ? p1 : p2;
	}
}


//LCA
void dfs(int cur, int depth) {
	H[cur] = idx;
	E[idx] = cur;
	L[idx++] = depth;
	for(auto x : adj[cur]) {
		dfs(x.first, depth+1);
		E[idx] = cur;
		L[idx++] = depth;
	}
}

void buildRMQ() {
	idx = 0;
	memset(H, -1, sizeof H);
	dfs(0, 0);
}

void go(int u) {
	for(auto x : adj[u]) {
		int v = x.first, w = x.second;
		dist[v] = dist[u] + w;
		go(v);
	}
}

int main() {
	int n,q,x,y,l;

	while(cin >> n && n) {
		adj.assign(MAX_N, {});

		for(int i=1; i<n; i++) {
			cin >> x >> l;
			adj[x].push_back(make_pair(i, l));
		}

		buildRMQ(); //build LCA
		build(1, 0, 2*n-1); //build segment tree

		dist[0] = 0;
		go(0);

		cin >> q;

		cin >> x >> y;
		int lca = E[query(1, 0, 2*n-1, min(H[x],H[y]), max(H[x],H[y]))];
		cout << dist[x] + dist[y] - 2*dist[lca];

		for(int i=1; i<q; i++) {
			cin >> x >> y;
			int lca = E[query(1, 0, 2*n-1, min(H[x],H[y]), max(H[x],H[y]))];
			cout << " " << dist[x] + dist[y] - 2*dist[lca];
		}
		cout << "\n";

	}

	return 0;
}

