#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n, ans = 0, cnt = 1;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=1; i<n; i++) {
		if(arr[i] == arr[i-1]) cnt++;
		else {
			for(int i=1; i<=cnt; i++) ans += 1+(cnt-i);
			cnt = 1;
		}
	}
	for(int i=1; i<=cnt; i++) ans += 1+(cnt-i);
	cout << ans;

	return 0;
}
