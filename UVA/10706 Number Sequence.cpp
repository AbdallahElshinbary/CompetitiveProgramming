#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int getLen(int n) {
	int x = (int)to_string(n).size()-1, ans = 0;
	while(n) {
		ans += (x+1)*(n-pow(10,x)+1);
		n=pow(10,x)-1, x--;
	}
	return ans;
}

int main() {
	ll x;
	vector<ll> v;
	v.push_back(0);
	v.push_back(getLen(1));
	for(int i=2; i<=100000; i++) {
		x = v.back() + getLen(i);
		v.push_back(x);
	}

	int t,n,p;
	cin >> t;
	while(t--) {
		cin >> n;
		p = upper_bound(v.begin(), v.end(), n) - v.begin() - 1;
		if(v[p] == n) p--;

		string s = "";
		int x = n-v[p]-1;
		for(int i=1; ;i++) {
			s += to_string(i);
			if((int)s.size() > x) {cout << s[x] << "\n"; break;}
		}
	}

	return 0;
}

