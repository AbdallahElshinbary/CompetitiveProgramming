#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, x;
	cin >> n;
	int arr[100005], mp[100005];
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=0; i<n; i++) {
		cin >> x;
		mp[x] = arr[i];
	}
	for(int i=0; i<n; i++) cout << mp[arr[i]] << " ";

	return 0;
}
