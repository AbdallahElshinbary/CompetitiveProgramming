#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,n,p,ans;
	int arr[105];
	cin >> t;
	while(t--) {
		cin >> n >> p;
		for(int i=0; i<p; i++) cin >> arr[i];

		ans = 0;
		for(int i=1; i<=n; i++) {
			if(i%7 == 0 || i%7 == 6) continue;
			for(int j=0; j<p; j++) if(i%arr[j] == 0) {ans++; break;}
		}
		cout << ans << "\n";
	}

	return 0;
}
