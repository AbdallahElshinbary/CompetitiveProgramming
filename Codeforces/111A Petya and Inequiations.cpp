#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n,x,y;
	cin >> n >> x >> y;
	y = y-n+1;
	if(y <= 0 || y*y + n-1 < x) {
		cout << -1;
		return 0;
	}
	for(int i=0; i<n-1; i++) cout << "1\n";
	cout << y;

	return 0;
}
