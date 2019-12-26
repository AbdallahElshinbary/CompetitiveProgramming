#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX_N 100005

int tree[4*MAX_N];
int tree2[4*MAX_N];
int s[MAX_N];
pair<int, int> arr[MAX_N];

void build(int p, int l, int r) {
	if(l == r) tree[p] = s[l];
	else {
		int mid = (l+r)/2;
		build(p*2, l, mid);
		build(p*2+1, mid+1, r);
		tree[p] = __gcd(tree[p*2], tree[p*2+1]);
	}
}

int query(int p, int l, int r, int i, int j) {
	if(i > r || j < l) return 0;
	if(i <= l && r <= j) return tree[p];
	int mid = (l+r)/2;
	int p1 = query(p*2, l, mid, i, j);
	int p2 = query(p*2+1, mid+1, r, i, j);
	return __gcd(p1, p2);
}

int main() {
	int n,t,l,r,x,y;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> s[i];
		arr[i] = make_pair(s[i], i);
	}
	build(1, 0, n-1);
	sort(arr, arr+n);

	cin >> t;
	while(t--) {
		cin >> l >> r;
		x = query(1, 0, n-1, l-1, r-1);
		y = upper_bound(arr, arr+n, make_pair(x, r-1)) - lower_bound(arr, arr+n, make_pair(x, l-1));
		cout << r-l+1 - y << "\n";
	}

	return 0;
}
















