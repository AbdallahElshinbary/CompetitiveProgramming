#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, k, x,y;
	cin >> n >> k;
	int arr[200005], freq[105]{};
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		arr[i] %= k;
		freq[arr[i]]++;
	}

	int ans=0;
	for(int i=0; i<n; i++) {
		x = arr[i], y = (k-arr[i])%k;
		if(freq[x]>0 && freq[y]>0) {
			if(x == y && freq[x] == 1) {freq[x]--; continue;}
			freq[x]--, freq[y]--, ans++;
		}
	}
	cout << ans*2;

	return 0;
}
