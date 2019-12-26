#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll fib[52];
	fib[0]=1, fib[1]=1;
	for(int i=2; i<52; i++) fib[i] = fib[i-1]+fib[i-2];

	ll t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int x = upper_bound(fib, fib+52, n) - fib;
		string s;
		for(int i=x-1; i>=1; i--) {
			if(n >= fib[i]) n-=fib[i], s.push_back('1');
			else s.push_back('0');
		}
		cout << s << "\n";
	}

	return 0;
}
