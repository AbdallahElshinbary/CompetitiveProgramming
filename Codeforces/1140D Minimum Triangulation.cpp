//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long ll;
//
//pair<int, int> arr[1000005];
//
//int main() {
//	int n, k;
//	ll ans = 0;
//	cin >> n >> k;
//	for(int i=0; i<n; i++) cin >> arr[i].first >> arr[i].second;
//	sort(arr, arr+n, greater<pair<int, int> >());
//
//	int ma, mb=1e9;
//	for(int i=0; i<k; i++) {
//		if(mb >= arr[i].second) ma=arr[i].first, mb=arr[i].second;
//		ans += arr[i].first;
//	}
//
//	int ca, cb=-1;
//	for(int i=k; i<n; i++)
//		if(cb < arr[i].second) ca=arr[i].first, cb=arr[i].second;
//
//	cout << max(ans*mb, (ans-ma+ca)*cb);
//
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n, ans=0;
	cin >> n;
	for(int i=2; i<n; i++)
		ans += i*(i+1);
	cout << ans;

	return 0;
}
