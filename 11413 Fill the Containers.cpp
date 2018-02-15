#include <bits/stdc++.h>
using namespace std;

int n,m, max_num, res, arr[1001];

void bs(int s, int e) {
	if(s > e)
		return;

	int mid = (s+e)/2, x, cnt=0, i=0;
	bool check;
	while(i < n) {
		x = mid;
		check = false;
		while(arr[i] <= x && i < n) {
			check = true;
			x -= arr[i];
			i++;
		}
		if(!check)
			break;
		cnt++;
	}

	if(cnt > m)
		return bs(mid+1, e);
	else if(cnt <= m) {
		res = mid;
		return bs(s, mid-1);
	}
}

int main() {
	while(cin >> n >> m) {
		max_num = 0;
		for(int i=0; i<n; i++) {
			cin >> arr[i];
			max_num = max(max_num, arr[i]);
		}
		bs(max_num, 1000000000);
		cout << res << "\n";
	}


	return 0;
}

