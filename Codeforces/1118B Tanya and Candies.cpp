#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,e=0,o=0,ans=0;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		if(i%2 == 0) o += arr[i];
		else e += arr[i];
	}

	int x=0, y=0;
	for(int i=0; i<n; i++) {
		if(i%2 == 0) {
			o -= arr[i];
			if(o+y == e+x) ans++;
			x += arr[i];
		} else {
			e -= arr[i];
			if(o+y == e+x) ans++;
			y += arr[i];
		}
	}
	cout << ans;

	return 0;
}
