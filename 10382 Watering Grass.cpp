#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	double l,w, pos, rad, x;
	while(cin >> n >> l >> w) {
		pair<double,double> arr[n];
		for(int i=0; i<n; i++) {
			cin >> pos >> rad;
			if(rad < w/2)
				continue;
			x = sqrt(rad*rad - (w/2)*(w/2));
			arr[i].first = (pos-x >= 0) ? pos-x : 0;
			arr[i].second = (pos+x <= l) ? pos+x : l;
		}
		sort(arr, arr+n);

		int i=0, cnt=0;
		double curr_pos=0, max_end;
		while(i < n && curr_pos < l) {
			max_end = -1;
			while(i < n && arr[i].first <= curr_pos)
				max_end = max(max_end, arr[i].second), i++;

			if(max_end == -1)
				break;

			cnt++;
			curr_pos = max_end;
		}

		cout << (curr_pos == l ? cnt : -1) << "\n";
	}

	return 0;
}
