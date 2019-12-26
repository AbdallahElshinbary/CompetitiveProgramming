#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX_N 5005

int tree[4*MAX_N];
int arr[MAX_N];
int n;

void build(int p, int l, int r) {
	if(l == r) tree[p] = l;
	else {
		int mid = (l+r)/2;
		build(p*2, l, mid);
		build(p*2+1, mid+1, r);
		int x = tree[p*2], y = tree[p*2+1];
		tree[p] = (arr[x] <= arr[y] ? x : y);
	}
}

int query(int p, int l, int r, int i, int j) {
	if(i > r || j < l) return -1;
	if(i <= l && r <= j) return tree[p];
	int mid = (l+r)/2;
	int x = query(p*2, l, mid, i, j);
	int y = query(p*2+1, mid+1, r, i, j);
	if(x == -1) return y;
	if(y == -1) return x;
	return (arr[x] <= arr[y] ? x : y);
}

int go(int l, int r, int d) {
	if(l > r) return 0;
	int mn = query(1, 0, n-1, l, r);
	return min(r-l+1, arr[mn]-d + go(l, mn-1, arr[mn]) + go(mn+1, r, arr[mn]));
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	build(1, 0, n-1);
	cout << go(0, n-1, 0);

	return 0;
}
















