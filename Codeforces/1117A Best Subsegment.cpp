#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	double arr[n];
	pair<double, int> best[n];
	double x;
	for(int i=0; i<n; i++) cin >> arr[i];

	best[n-1] = {arr[n-1], 1};
	for(int i=n-2; i>=0; i--) {
		x = (arr[i]+best[i+1].first)/2;
		if(x >= arr[i]) best[i] = {x, best[i+1].second+1};
		else best[i] = {arr[i], 1};
	}

	sort(best, best+n, greater<pair<double, int> >());
	cout << best[0].second;

	return 0;
}
