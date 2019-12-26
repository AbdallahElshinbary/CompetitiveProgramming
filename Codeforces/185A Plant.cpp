#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007

ll power(ll n, ll p){
	ll cur, res;
	cur = n;
	res = 1;
	while(p){
		if(p%2 == 1){
			res *= cur;
			res %= MOD;
		}
		p /= 2;
		cur *= cur;
		cur %= MOD;
	}
	return res;
}

int main() {
	ll n;
	cin >> n;

	ll x = power(2, n);
	cout << ((x)*((x+1))/2)%MOD;

	return 0;
}
