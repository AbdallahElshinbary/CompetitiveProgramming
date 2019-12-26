#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, ans=0;
	cin >> n;
	string arr[n];
	bool vis[n]{};

	for(int i=0; i<n; i++) cin >> arr[i];

	for(int i=0; i<n; i++) {
		if(vis[i]) continue;
		for(int j=i+1; j<n; j++) {
			if(vis[j]) continue;
			if(stoll(arr[i]+arr[j]) % 3 == 0 || stoll(arr[j]+arr[i]) % 3 == 0) {
				ans++, vis[i]=vis[j]=true;
				break;
			}
		}
	}
	cout << ans;

	return 0;
}
