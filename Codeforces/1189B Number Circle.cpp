#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	int arr[100005];
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);
	if(arr[n-2] + arr[n-3] <= arr[n-1]) cout << "NO\n";
	else {
		cout << "YES\n";
		cout << arr[n-3] << " ";
		for(int i=0; i<n-3; i++) cout << arr[i] << " ";
		cout << arr[n-2] << " " << arr[n-1];
	}

	return 0;
}

