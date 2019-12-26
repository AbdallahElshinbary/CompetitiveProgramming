#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	int arr[105];
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];

	int mn,mx,x,y,z;
	mn = *min_element(arr, arr+n);
	mx = *max_element(arr, arr+n);
	x = (mn+mx);
	if(x%2 == 0) y = x/2, z=mx-x/2;
	else y = mn, z=mx-mn;

	for(int i=0; i<n; i++)
		if(arr[i] != mn && arr[i] != mx && arr[i] != y) {cout << -1; return 0;}
	cout <<z << endl;

	return 0;
}
