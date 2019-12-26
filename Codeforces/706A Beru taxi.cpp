#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a,b,n,x,y,v;

double dist() {
	return sqrt((a-x)*(a-x) + (b-y)*(b-y)) / v;
}

int main() {
	double ans = 1e7;
	cin >> a >> b >> n;

	for(int i=0; i<n; i++) {
		cin >> x >> y >> v;
		ans = min(ans, dist());
	}
	printf("%.13f", ans);

	return 0;
}
