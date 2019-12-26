#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, ans=0;
	int arr[10005];
	cin >> n;
	for(int i=1; i<=n; i++) cin >> arr[i];

	int x=-1;
	for(int i=1; i<=n; i++) {
		x = max(x, arr[i]);
		if(i >= x) ans++, x=arr[i];
	}
	cout << ans;

	return 0;
}
