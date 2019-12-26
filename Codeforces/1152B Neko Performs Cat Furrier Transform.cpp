#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> lc;
vector<int> ans;

bool good(int n) {
	return n && (!(n&(n+1)));
}

bool go(int t, int n) {
	if(good(t)) {
		cout << n-1 << "\n";
		for(int x : ans) cout << x << " ";
		return 1;
	}
	if(n == 40) return 0;

	if(n%2) {
		for(int i=ceil(log2(t)); i<31; i++) {
			ans.push_back(i);
			if(go((t^lc[i]), n+1)) return 1;
			else ans.pop_back();
		}
	} else {
		if(go(t+1, n+1)) return 1;
	}
	return 0;
}

int main() {
	for(int i=0; i<31; i++) lc.push_back(pow(2, i)-1);

	int t;
	cin >> t;
	go(t, 1);

	return 0;
}


















