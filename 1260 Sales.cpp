#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,cnt;
	int arr[1005];
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; i++)
			cin >> arr[i];
		cnt=0;
		for(int i=0; i<n; i++) {
			for(int j=i-1; j>=0; j--)
				if(arr[j] <= arr[i]) cnt ++;
		}
		cout << cnt << "\n";
	}

	return 0;
}

