#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,n,k;
	int arr[105];
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i=0; i<n; i++) cin >> arr[i];
		int mn = *min_element(arr, arr+n);
		int mx = *max_element(arr, arr+n);

		int a = mn+k, b = mx-k;
		if(b > a) {cout << "-1\n"; continue;}
		cout << a << "\n";
	}

	return 0;
}







