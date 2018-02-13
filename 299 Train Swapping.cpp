#include <bits/stdc++.h>
using namespace std;

int main() {

	int t,n, arr[55];
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; i++)
			cin >> arr[i];

		int cnt = 0;
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				if(arr[i] > arr[j])
					cnt++;

		cout << "Optimal train swapping takes " << cnt << " swaps.\n";
	}
}

