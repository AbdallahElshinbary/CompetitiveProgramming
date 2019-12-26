#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,x,o=0;
	int arr[5000];
	cin >> n;
	n *= 2;

	cin >> arr[0];
	x = arr[0];

	for(int i=1; i<n; i++) {
		cin >> arr[i];
		if(arr[i] != x) o=1;
	}

	if(!o) {cout << -1; return 0;}

	sort(arr, arr+n);
	for(int i=0; i<n; i++) cout << arr[i] << " ";

	return 0;
}
