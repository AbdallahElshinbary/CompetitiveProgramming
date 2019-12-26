#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll k,a,b;
	cin >> k >> a >> b;

	ll x = (a/k)*k;
	if(x < a) x += k;

	ll c = (b-x+1);
	if(c < 0) cout << 0;
	else if(c%k == 0) cout << c/k;
	else cout << (c/k)+1;

	return 0;
}
