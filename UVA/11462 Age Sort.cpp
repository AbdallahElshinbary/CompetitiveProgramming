#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int arr[2000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while(cin >> n && n) {
		for(int i=0; i<n; i++) cin >> arr[i];
		sort(arr, arr+n);
		cout << arr[0];
		for(int i=1; i<n; i++) cout << " " << arr[i];
		cout << "\n";
	}

	return 0;
}




}