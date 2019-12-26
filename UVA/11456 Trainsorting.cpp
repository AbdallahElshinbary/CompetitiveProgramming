#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,n;
	int arr[2005], LIS[2005], LDS[2005];
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; i++) cin >> arr[i];
		fill(LIS, LIS+n, 1);
		fill(LDS, LDS+n, 1);

		reverse(arr, arr+n);

		for(int i=0; i<n; i++)
			for(int j=0; j<i; j++)
				if(arr[j] < arr[i])
					LIS[i] = max(LIS[i], 1+LIS[j]);

		for(int i=0; i<n; i++)
			for(int j=0; j<i; j++)
				if(arr[j] > arr[i])
					LDS[i] = max(LDS[i], 1+LDS[j]);

		int mx = 0;
		for(int i=0; i<n; i++) mx = max(mx, LIS[i]+LDS[i]-1);
		cout << mx << "\n";
	}

	return 0;
}
