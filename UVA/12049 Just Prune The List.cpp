#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,n,m,i,j,ans;
	int a[10005], b[10005];
	cin >> t;
	while(t--) {
		cin >> n >> m; ans=0;
		for(i=0; i<n; i++) cin >> a[i];
		for(i=0; i<m; i++) cin >> b[i];
		sort(a, a+n);
		sort(b, b+m);
		for(i=0, j=0; i<n && j<m; ) {
			if(a[i] < b[j]) i++, ans++;
			else if(a[i] > b[j]) j++, ans++;
			else i++, j++;
		}
		ans += (n-i)+(m-j);
		cout << ans << "\n";
	}
	return 0;
}



