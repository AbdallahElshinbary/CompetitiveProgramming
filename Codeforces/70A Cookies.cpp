#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000003

int rec(int n) {
	if(n <= 1) return 1;
	return (3*rec(n-1))%MOD;
}


int main() {
	int n;
	cin >> n;
	cout << rec(n);

	return 0;
}
