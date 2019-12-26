#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll XOR(ll n) {
	switch(n%4) {
		case 0: return n;
		case 1: return 1;
		case 2: return n+1;
		case 3: return 0;
	}
}

int main() {
	ll n,x,m,ans=-1;
	cin >> n;
	while(n--) {
		cin >> x >> m;
		if(ans == -1) ans = XOR(x+m-1)^XOR(x-1);
		else ans ^= XOR(x+m-1)^XOR(x-1);
	}
	cout << (ans == 0 ? "bolik" : "tolik");

	return 0;
}
