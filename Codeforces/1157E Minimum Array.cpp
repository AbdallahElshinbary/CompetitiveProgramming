#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,x;
	int a[200005], freq[200005]{};
	set<int> b;

	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) {
		cin >> x; freq[x]++; b.insert(x);
	}

	for(int i=0; i<n; i++) {
		auto idx = b.lower_bound(n-a[i]);
		if(idx == b.end()) idx = b.begin();
		x = *idx;
		freq[x]--; cout << (a[i]+x)%n << " ";
		if(freq[x] == 0) b.erase(idx);
	}


	return 0;
}
