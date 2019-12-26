#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n,x,cnt=0;
	ll arr[100005];
	map<ll, int> mp;
	cin >> n;
	for(int i=0; i<n; i++) {cin >> arr[i]; mp[arr[i]]+=1;}
	for(int i=0; i<n; i++) {
		for(int j=1; j<=32; j++) {
			x = (1LL << j) - arr[i];
			if(x == arr[i]) cnt += mp[x]-1;
			else cnt += mp[x];
		}
	}
	cout << (cnt/2) << "\n";

	return 0;
}



