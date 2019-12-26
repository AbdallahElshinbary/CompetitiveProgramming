#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);

	ll x = 1;
	int y = 1;

	for(int i=3; i<n; i++) {
		if(arr[i] == arr[2]) x++;
		else break;
	}

	if(arr[2] == arr[1]) {
		x++, y++;
		if(arr[1] == arr[0]) x++, y++;
	}

	if(y == 1) cout << x;
	else if(y == 2) cout << (x*(x-1)/2);
	else if(y == 3) cout << (x*(x-1)*(x-2)/6);

	return 0;
}
