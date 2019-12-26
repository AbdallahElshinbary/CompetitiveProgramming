#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, x, m;
	int arr[55];
	while(cin >> n && n) {
		x = m = 0;
		for(int i=0; i<n; i++) cin >> arr[i];
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(__gcd(arr[i], arr[j]) == 1) x++;
				m++;
			}
		}
		if(x == 0) cout << "No estimate for this data set.\n";
		else cout << fixed << setprecision(6) << sqrt((6.0*m/x)) << "\n";
	}

	return 0;
}
