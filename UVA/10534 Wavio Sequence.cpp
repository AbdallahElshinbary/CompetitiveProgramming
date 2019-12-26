#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, p, mn;
	int arr[10005];
	vector<int> LIS, v1, v2;

	while(cin >> n) {
		for(int i=0; i<n; i++) cin >> arr[i];
		if(n < 3) {cout << "1\n"; continue;}

		LIS.clear();
		for(int i=0; i<n; i++) {
			p = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();
			if(p == (int)LIS.size()) {LIS.push_back(arr[i]); v1.push_back(i);}
			else LIS[p] = arr[i];
		}

		LIS.clear();
		for(int i=n-1; i>=0; i--) {
			p = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();
			if(p == (int)LIS.size()) {LIS.push_back(arr[i]); v2.push_back(i);}
			else LIS[p] = arr[i];
		}

		bool done=0;
		mn = (int)min(v1.size(), v2.size());
		for(int i=1; i<mn; i++)
			if(v1[i] > v2[i]) {cout << 2*(i) - 1 << "\n"; done=1; break;}

		if(!done) cout << (2*(mn) - 1) << "\n";
		v1.clear(); v2.clear();
	}

	return 0;
}
