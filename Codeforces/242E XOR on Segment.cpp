#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX_N 100005

int tree[22][4*MAX_N];
bool flipped[22][4*MAX_N];
int arr[MAX_N];

void build(int x, int p, int l, int r) {
	if(l == r)
		tree[x][p] = ((arr[l]&(1<<x)) ? 1 : 0);
	else {
		int mid = (l+r)/2;
		build(x, p*2, l, mid);
		build(x, p*2+1, mid+1, r);
		tree[x][p] = tree[x][p*2] + tree[x][p*2+1];
	}
}

void update(int x, int p, int l, int r, int i, int j) {
	if(flipped[x][p]) {
		tree[x][p] = (r-l+1) - tree[x][p];
		if(l != r) {
			flipped[x][p*2] ^= 1;
			flipped[x][p*2+1] ^= 1;
		}
		flipped[x][p] = 0;
	}

	if(l > r || i > r || j < l) return;
	if(i <= l && r <= j) {
		tree[x][p] = (r-l+1) - tree[x][p];
		if(l != r) {
			flipped[x][p*2] ^= 1;
			flipped[x][p*2+1] ^= 1;
		}
		return;
	}
	int mid = (r+l)/2;
	update(x, p*2, l, mid, i, j);
	update(x, p*2+1, mid+1, r, i, j);
	tree[x][p] = tree[x][p*2] + tree[x][p*2+1];
}

int query(int x, int p, int l, int r, int i, int j) {
	if(i > r || j < l) return 0;
	if(flipped[x][p]) {
		tree[x][p] = (r-l+1) - tree[x][p];
		if(l != r) {
			flipped[x][p*2] ^= 1;
			flipped[x][p*2+1] ^= 1;
		}
		flipped[x][p] = 0;
	}
	if(i <= l && r <= j) return tree[x][p];

	int mid = (r+l)/2;
	int p1 = query(x, p*2, l, mid, i, j);
	int p2 = query(x, p*2+1, mid+1, r, i, j);
	return p1+p2;
}

int main() {
	int n,m,t,l,r,x;
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=0; i<=20; i++) build(i, 1, 0, n-1);

	cin >> m;
	while(m--) {
		cin >> t >> l >> r;
		if(t == 1) {
			ll ans = 0;
			for(int i=0; i<=20; i++) {
				int x = query(i, 1, 0, n-1, l-1, r-1);
				ans += (ll)x*(1<<i);
			}
			cout << ans << "\n";
		} else {
			cin >> x;
			for(int i=0; i<=20; i++)
				if(x&(1<<i)) update(i, 1, 0, n-1, l-1, r-1);
		}
	}

	return 0;
}
















