#include <bits/stdc++.h>
using namespace std;

int main() {
	int l,g, r, x;
	while(cin >> l >> g && l!=0 && g!=0) {
		pair<int,int> arr[g];
		for(int i=0; i<g; i++) {
			cin >> r >> x;
			arr[i].first = (r-x >= 0) ? r-x : 0;
			arr[i].second = (r+x <= l) ? r+x : l;
		}
		sort(arr, arr+g);

		int i=0, curr_pos=0, max_end, cnt=0;
		while(i < g && curr_pos < l) {
			max_end = -1;
			while(i < g && arr[i].first <= curr_pos)
				max_end = max(max_end, arr[i].second), i++;

			if(max_end == -1)
				break;

			cnt++;
			curr_pos = max_end;
		}

		cout << (curr_pos == l ? g-cnt : -1) << "\n";
	}

	return 0;
}

