#include <bits/stdc++.h>
using namespace std;

int main() {
	int T,n;
	cin >> T;
	for(int t=1; t<=T; t++) {
		cin >> n;
		char arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];

		int cnt=0;
		for(int i=1; i<n; i++) {
			if(arr[i-1] == '.') {
				arr[i-1] = arr[i] = '#';
				if(i != n-1) arr[i+1] = '#';
				cnt++;
			}
		}
		if(arr[n-1] == '.')
			cnt++;

		cout << "Case " << t << ": " << cnt << "\n";
	}

	return 0;
}

