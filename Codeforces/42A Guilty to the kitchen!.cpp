#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
	int n, v;
	cin >> n >> v;
	int a[n], b[n];
	double sum;
	for(int i=0; i<n; i++) {cin >> a[i]; sum += a[i];}
	for(int i=0; i<n; i++) cin >> b[i];

	double x, ans = v;
	for(int i=0; i<n; i++) {
		x = b[i]*sum/a[i];
		ans = min(ans, x);
	}
	cout << ans;

	return 0;
}
