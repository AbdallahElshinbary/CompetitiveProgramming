#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, k;
	vector<pair<int, int> > v;
	cin >> n >> k;

	int cnt=0;
	for(int i=1; i<=k; i++) {
		for(int j=i+1; j<=k; j++) {
			cnt += 2;
			v.push_back(make_pair(i,j));
			v.push_back(make_pair(j,i));
			if(cnt >= n) break;
		}
		if(cnt == n) break;
	}
	if(cnt < n) cout << "NO";
	else {
		cout << "YES\n";
		for(int i=0; i<n; i++) cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}
