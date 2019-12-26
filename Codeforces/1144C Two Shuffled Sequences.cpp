#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	int arr[200005], freq[200005]{};
	memset(arr, -1, sizeof arr);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		if(++freq[arr[i]] > 2) {
			cout << "NO";
			return 0;
		}
	}
	sort(arr, arr+n);

	cout << "YES\n";
	int x = (n%2 == 0 ? n-1 : n-2);
	if(n%2 == 0) cout << n/2 << "\n";
	else cout << n/2 + 1 << "\n";

	for(int i=0; i<n; i+=2) cout << arr[i] << " ";
	cout << "\n" << n/2 << "\n";
	for(int i=x; i>=0; i-=2) cout << arr[i] << " ";

	return 0;
}
