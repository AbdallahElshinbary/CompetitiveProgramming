#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool arr[1000000];

int main() {
	int n, temp=0, ans=0;
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=n; i<2*n; i++) arr[i] = arr[i-n];

	for(int i=0; i<2*n; i++) {
		if(arr[i] == 1) temp++;
		else ans = max(ans, temp), temp=0;
	}
	ans = max(ans, temp);
	cout << ans;

	return 0;
}
