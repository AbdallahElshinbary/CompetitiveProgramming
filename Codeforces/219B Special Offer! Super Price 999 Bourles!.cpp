#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int get(ll n, int pos) {
	int x;
	while(pos) {
		x=n%10, n/=10; pos--;
	}
	return x;
}

int len(ll n) {
	int x=0;
	while(n) x++, n/=10;
	return x;
}

int main() {
	ll n, d, x, y, sum=0;
	cin >> n >> d;
	if(n < 9) {
		cout << n << endl;
		return 0;
	}

	int i=1;
	while(true) {
		if(i > len(n)) break;
		x = get(n, i++);
		if(x == 9) continue;
		y = (x+1) * powl(10, i-2);
		sum += y;
		if(sum > d) break;
		n -= y;
	}
	cout << n << endl;

	return 0;
}
