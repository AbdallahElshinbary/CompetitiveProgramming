#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<int, int> freq;

void factorize(int n) {
	freq[1]++, freq[n]++;
	int i;
	for(i=2; i*i<n; i++)
		if(n%i == 0) freq[i]++, freq[n/i]++;
	if(i*i == n) freq[i]++;
}

int main() {
	vector<int> v;
	int a,b,q,l,h,x;
	cin >> a >> b;
	factorize(a); factorize(b);
	for(auto f : freq)
		if(f.second > 1) v.push_back(f.first);
	sort(v.begin(), v.end());

	cin >> q;
	while(q--) {
		cin >> l >> h;
		x = lower_bound(v.begin(), v.end(), h) - v.begin();
		if(x == (int)v.size() || v[x] > h) x--;
		if(x == -1 || v[x] < l) cout << -1 << "\n";
		else cout << v[x] << "\n";
	}

	return 0;
}
