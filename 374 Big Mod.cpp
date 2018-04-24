#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll POW(ll b, ll p, ll m) {
	if(p == 0) return 1;

	ll sq = POW(b, p/2, m);
	sq = ((sq%m)*(sq%m))%m;

	if(p%2 != 0)
		sq = ((sq%m)*(b%m))%m;

	return sq;
}

int main()
{
	ll b,p,m;
	while(cin >> b >> p >> m)
		cout << POW(b,p,m) << endl;

	return 0;
}



