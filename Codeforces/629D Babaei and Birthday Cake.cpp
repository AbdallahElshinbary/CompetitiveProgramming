#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;

#define mp make_pair
#define MAX_N 100005
#define PI 3.14159265359

ll tree[4*MAX_N];
ll vol[MAX_N];
vector<ii> v;
ll n,r,h, ans=0;

void update(int p, int l, int r, int idx, ll val) {
	if(l == r) tree[p] = val;
	else {
		int mid = (l+r)/2;
		if(idx <= mid) update(p*2, l, mid, idx, val);
		else update(p*2+1, mid+1, r, idx, val);
		tree[p] = max(tree[p*2], tree[p*2+1]);
	}
}

ll query(int p, int l, int r, int i, int j) {
	if(i > r || j < l) return 0;
	if(i <= l && r <= j) return tree[p];
	int mid = (l+r)/2;
	return max(query(p*2, l, mid, i, j), query(p*2+1, mid+1, r, i, j));
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> r >> h;
		vol[i] = r*r*h;
		v.push_back(mp(vol[i], -i));
	}
	sort(v.begin(), v.end());

	for(int i=0; i<n; i++) {
		int idx = -v[i].second;
		ll mxi = vol[idx] + query(1, 0, n-1, 0, idx-1);
		ans = max(ans, mxi);
		update(1, 0, n-1, idx, mxi);
	}
	printf("%.9lf", PI*ans);

	return 0;
}








