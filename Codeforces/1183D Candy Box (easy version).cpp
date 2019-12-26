#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,n,x;
	int freq[200005];
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<=n; i++) freq[i]=0;
		for(int i=0; i<n; i++) {cin >> x; freq[x]++;}
		sort(freq, freq+n+1, greater<int>());
		int p = 1e9, ans=0;
		for(int i=0; i<n; i++) {
			if(freq[i] >= p) p = p-1;
			else p = freq[i];
			if(p == 0) break;
			ans += p;
		}
		cout << ans << "\n";
	}


	return 0;
}







