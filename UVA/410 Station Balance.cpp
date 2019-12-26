#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int c, s, n, t=1;
	double avg, ans;
	while(cin >> c >> s) {
		avg = ans = 0;
		n = 2*c;
		int arr[n]{};
		for(int i=0; i<s; i++) {
			cin >> arr[i];
			avg += arr[i];
		}
		avg /= c;
		sort(arr, arr+n);

		cout << "Set #" << t++ << "\n";
		for(int i=0; i<n/2; i++) {
			cout << " " << i << ":";
			if(arr[i] != 0) cout << " " << arr[i];
			if(arr[n-i-1] != 0) cout << " " << arr[n-i-1];
			ans += abs((arr[i]+arr[n-i-1])-avg);
			cout << "\n";
		}
		cout << fixed << setprecision(5) << "IMBALANCE = " << ans << "\n\n";
	}

	return 0;
}
