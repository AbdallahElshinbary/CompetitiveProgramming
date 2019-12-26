#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll mx = 4294967295;
	ll l,n,x=0;
	string s;

	ll p = 1, r = 0;
	stack<ll> st;

	cin >> l;
	while(l--) {
		cin >> s;
		if(s == "for") {
			cin >> n;
			if(p > mx) {
				r++;
				continue;
			}
			p *= n;
			st.push(n);
		}

		else if(s == "end") {
			if(r) {r--; continue;}
			p /= st.top();
			st.pop();
		}
		else if(s == "add") {
			x += p;
			if(x > mx) {
				cout << "OVERFLOW!!!";
				return 0;
			}
		}
	}
	cout << x;

	return 0;
}
