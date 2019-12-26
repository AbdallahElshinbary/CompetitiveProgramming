#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class FenwickTree {
private:
	vector<ll> ft;
public:
	void init(int n) { ft.assign(n + 1, 0); }
	int LSOne(int i) {return (i & (-i));}
	ll query(int b) {
		ll sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}
	ll query(int a, int b) { return query(b) - query(a - 1); }
	void update(int k, ll v) {
		for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
	}
};

FenwickTree ft[15];
int n,k;
int arr[100005];

int main() {
	cin >> n >> k;

	k++;
	for(int i=0; i<=k; i++) ft[i].init(n);
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
		ft[1].update(arr[i], 1);	//dp[1][a[i]] = 1
		for(int j=2; j<=k; j++) ft[j].update(arr[i], ft[j-1].query(arr[i]-1));		//dp[j][a[i]] = sumOf(dp[j-1][1..a[i]-1])
	}
	cout << ft[k].query(n);

	return 0;
}







