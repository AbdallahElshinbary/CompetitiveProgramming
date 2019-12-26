#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
	int n,x,y;
	cin >> n;

	map<int, int> freq1, freq2;
	while(n--) {
		cin >> x >> y;
		freq1[x+y]++, freq2[x-y]++;
	}

	ll ans = 0;
	for(auto x : freq1) ans += (x.second*(x.second-1))/2;
	for(auto x : freq2) ans += (x.second*(x.second-1))/2;
	cout << ans;

	return 0;
}
