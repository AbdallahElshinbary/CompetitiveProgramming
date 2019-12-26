#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,p;
	int arr[100005];
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];

	vector<int> v;
	for(int i=0; i<n; i++) {
		p = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		if(p == (int)v.size()) v.push_back(arr[i]);
		else v[p] = arr[i];
	}

	cout << v.size();

	return 0;
}





























