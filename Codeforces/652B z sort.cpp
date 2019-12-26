#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	int arr[1005], ans[1005];
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);

	int i=0, j=(n/2 + (n&1)), k=0;
	while(j < n) {
		ans[k++] = arr[i++];
		ans[k++] = arr[j++];
	}
	if(n&1) ans[k] = arr[i];
	for(int i=0; i<n; i++) cout << ans[i] << " ";



	return 0;
}



