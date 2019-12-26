#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sol(int n) {
	if(n/10 == 0) return (n == 0 ? 1 : n);

	int x=n%10;
	if(x == 9) return (x*sol(n/10));
	return max(9*sol((n-10)/10), x*sol(n/10));
}

int main() {
	int n;
	cin >> n;
	cout << sol(n);

	return 0;
}
