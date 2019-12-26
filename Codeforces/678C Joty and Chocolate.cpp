#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n,a,b,p,q,ans=0;
	cin >> n >> a >> b >> p >> q;

	ans += (n/a)*p;
	ans += (n/b)*q;
	ans -= (n/((a*b)/__gcd(a,b)))*min(p,q);
	cout << ans;


	return 0;
}
