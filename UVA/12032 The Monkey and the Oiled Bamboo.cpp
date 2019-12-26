#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t,n,ans=1e9;
int arr[100005]{};

void bs(int s, int e) {
	if(s > e) return;
	int m = (s+e)/2;
	int t = m;
	bool ok = true;
	for(int i=1; i<=n; i++) {
		if(arr[i]-arr[i-1] > t) {ok=false; break;}
		else if(arr[i]-arr[i-1] == t) t--;
	}
	if(ok) {ans = min(ans, m); bs(s, m-1);}
	else bs(m+1, e);
}

int main() {
	arr[0] = 0;
	cin >> t;
	for(int T=1; T<=t; T++) {
		cin >> n;
		for(int i=1; i<=n; i++) cin >> arr[i];
		ans = 1e9;
		bs(1, 100000000);
		cout << "Case " << T << ": " << ans << "\n";
	}

	return 0;
}
