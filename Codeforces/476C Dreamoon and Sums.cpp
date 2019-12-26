#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int m = 1e9+7;

int main() {
	ll a,b;
	cin >> a >> b;
	cout << (((((((a*(a+1)/2)%m)*b%m)%m) + a)%m)* ((b*(b-1)/2)%m)) %m;

	return 0;
}

