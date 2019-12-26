#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int d, arr[3];
	cin >> arr[0] >> arr[1] >> arr[2] >> d;
	sort(arr, arr+3);

	int ans = 0;
	ans += max(0, d-(arr[1]-arr[0]));
	ans += max(0, d-(arr[2]-arr[1]));
	cout << ans;


	return 0;
}




























