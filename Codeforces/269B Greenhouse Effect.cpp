#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define eps 1e-7

int main() {
	int n,m;
	pair<int, double> arr[5005];
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> arr[i].first >> arr[i].second;

	int LIS[5005];
	fill(LIS, LIS+5005, 1);

	for(int i=0; i<n; i++)
		for(int j=0; j<i; j++)
			if(arr[j].first <= arr[i].first)
				LIS[i] = max(LIS[i], 1+LIS[j]);

	int mx=0;
	for(int i=0; i<n; i++) mx = max(mx, LIS[i]);
	cout << n-mx;


	return 0;
}





























