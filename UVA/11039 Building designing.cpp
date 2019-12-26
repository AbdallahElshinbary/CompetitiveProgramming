#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool red[1000005];
int arr[1000005];

int main() {
	int t,n,x,cnt;
	cin >> t;
	while(t--) {
		cin >> n;
		if(n == 0) {
			cout << "0\n";
			continue;
		}
		for(int i=0; i<n; i++) {
			cin >> x;
			if(x > 0) red[abs(x)] = false;
			else red[abs(x)] = true;
			arr[i] = abs(x);
		}
		sort(arr, arr+n, greater<int>());

		cnt = 1;
		bool flag = red[arr[0]];
		for(int i=1; i<n; i++) {
			if(red[arr[i]] == flag) continue;
			else {
				cnt++;
				flag = !flag;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}
