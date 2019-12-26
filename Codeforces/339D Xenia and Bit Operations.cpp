#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int tree[4*100005], arr[200005];

void build(int p, int L, int R, int f) {
	if(L == R)
		tree[p] = arr[L];
	else {
		int mid = (L+R)/2;
		build(p*2, L, mid, !f);
		build(p*2+1, mid+1, R, !f);
		tree[p] = (f ? tree[p*2]|tree[p*2+1] : tree[p*2]^tree[p*2+1]);
	}
}

int query(int p, int L, int R, int i, int j, int f) {
	if(i > R || j < L)
		return 0;
	if(i <= L && R <= j) return tree[p];
	int mid = (L+R)/2;
	int p1 = query(p*2, L, mid, i, j, !f);
	int p2 = query(p*2+1, mid+1, R, i, j, !f);
	return (f ? p1|p2 : p1^p2);
}

void update(int p, int L, int R, int idx, int val, int f) {
	if(L == R)
		tree[p] = val;
	else {
		int mid = (L+R)/2;
		if(idx <= mid)
			update(p*2, L, mid, idx, val, !f);
		else
			update(p*2+1, mid+1, R, idx, val, !f);
		tree[p] = (f ? tree[p*2]|tree[p*2+1] : tree[p*2]^tree[p*2+1]);
	}
}

int main() {
	int n, m, x, a, b;
	cin >> x >> m;
	n = 1<<x;
	for(int i=0; i<n; i++) cin >> arr[i];
	build(1, 0, n-1, (x&1));

	while(m--) {
		cin >> a >> b;
		update(1, 0, n-1, a-1, b, (x&1));
		cout << query(1, 0, n-1, 0, n-1, (x&1)) << "\n";
	}

	return 0;
}











