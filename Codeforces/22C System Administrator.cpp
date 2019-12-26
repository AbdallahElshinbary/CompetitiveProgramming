#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,m,v;
	int arr[100005];
	cin >> n >> m >> v;
	if(m < n-1 || m > ((n-1)*(n-2)/2 + 1)) {cout << -1; return 0;}
	for(int i=1; i<=n; i++) arr[i] = i;
	swap(arr[v], arr[n-1]);
	cout << arr[n-1] << " " << arr[n] << "\n"; m--;
	for(int i=1; i<n-1; i++) {
		for(int j=n-1; j>i; j--) {
			cout << arr[i] << " " << arr[j] << "\n";
			if(--m == 0) break;
		}
		if(m == 0) break;
	}

	return 0;
}
