#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	while(t--) {
		int l,n, avg, diff=INT_MAX, mini;
		cin >> l >> n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];
		sort(arr, arr+n);

		avg = l/2;
		for(int i=0; i<n; i++) {
			if(abs(arr[i]-avg) < diff) {
				diff = abs(arr[i]-avg);
				mini = arr[i];
			}
		}

		cout << min(l-mini, mini) << " " << max(l-arr[0], arr[n-1]) << "\n";
	}
	return 0;
}

