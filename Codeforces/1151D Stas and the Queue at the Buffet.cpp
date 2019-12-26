#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, pair<ll, ll> > arr[100005];

int main() {
	ll n,a,b,ans = 0;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a >> b;
		arr[i].first = a-b;
		arr[i].second.first = a, arr[i].second.second = b;
	}
	sort(arr+1, arr+n+1, greater<pair<ll, pair<ll, ll> > >());
	for(ll i=1; i<=n; i++) {
		a = arr[i].second.first, b = arr[i].second.second;
		ans += a*(i-1) + b*(n-i);
	}
	cout << ans;


	return 0;
}













