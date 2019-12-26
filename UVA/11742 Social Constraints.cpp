#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
	int n,m,a,b,c,x,y,cnt;
	while(cin >> n >> m && n) {
		pair<pair<int, int>, int> cons[m];
		for(int i=0; i<m; i++) {
			cin >> a >> b >> c;
			cons[i] = {{a,b},c};
		}

		int arr[n];
		for(int i=0; i<n; i++) arr[i]=i;

		cnt = 0;
		bool ok;
		do {
			ok = true;
			for(auto con : cons) {
				x = find(arr, arr+n, con.first.first)-arr;
				y = find(arr, arr+n, con.first.second)-arr;
				if(con.second > 0) ok &= (abs(x-y) <= con.second);
				else ok &= (abs(x-y) >= abs(con.second));
			}
			if(ok) cnt++;
		} while(next_permutation(arr, arr+n));

		cout << cnt << "\n";
	}

	return 0;
}
