#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, l=0, r=0, k=0;
	int arr[200005];

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		if(arr[i] == 0) l++;
		else r++;
	}

	for(int i=0; i<n; i++) {
		if(arr[i] == 0) l--;
		else r--;
		k++;
		if(l == 0 || r == 0) {cout << k; return 0;}
	}

	return 0;
}
