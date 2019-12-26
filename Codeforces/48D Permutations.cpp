#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, ans=0;
	int arr[100005], freq[100005]{}, idx[100005]{};
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		freq[arr[i]]++;
	}

	for(int i=0; i<n; i++) if(arr[i] != 1 && freq[arr[i]] > freq[arr[i]-1]) {cout << -1; return 0;}
	for(int i=0; i<n; i++) arr[i] = ++idx[arr[i]];

	ans = *max_element(arr, arr+n);
	cout << ans << "\n";
	for(int i=0; i<n; i++) cout << arr[i] << " ";

	return 0;
}
