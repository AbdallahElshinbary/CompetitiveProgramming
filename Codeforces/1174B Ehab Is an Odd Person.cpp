#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,o=0,e=0;
	int arr[100005];

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		if(arr[i] & 1) o++;
		else e++;
	}

	if(o && e) sort(arr, arr+n);
	for(int i=0; i<n; i++) cout << arr[i] << " ";

	return 0;
}
