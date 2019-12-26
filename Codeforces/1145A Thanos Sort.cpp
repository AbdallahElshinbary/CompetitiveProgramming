#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int arr[20];

bool check(int n, int x) {
	for(int i=0; i<n; i+=x)
		if(is_sorted(arr+i, arr+i+x)) return true;
	return false;
}

int main() {
	int n, x;
	cin >> n;
	x = n;
	for(int i=0; i<n; i++) cin >> arr[i];
	while(x != 1) {
		if(check(n, x)) {cout << x; return 0;}
		x /= 2;
	}
	cout << 1;

	return 0;
}
