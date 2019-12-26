//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//	int t,n;
//	string s;
//
//	cin >> t;
//	while(t--) {
//		cin >> s;
//		n = (int)s.size();
//		sort(s.begin(), s.end());
//
//		for(int i=0; i<n-1; i++) {
//			if(s[i])
//		}
//	}
//
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,z,x,ans=0;
	int a[200005];
	int b[200005]{};

	cin >> n >> z;
	for(int i=0; i<n; i++) cin >> a[i];

	sort(a, a+n);
	for(int i=0; i<n/2; i++) {
		x = lower_bound(a, a+n, a[i]+z) - a;
		b[x]++;
	}

	int c=0;
	for(int i=1; i<n; i++) {
		if(b[i]) c += b[i];
		if(c) ans++, c--;
	}

	cout << ans;

	return 0;
}
