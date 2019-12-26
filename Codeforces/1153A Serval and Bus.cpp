#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	pair<int, int> times[105], sr[105];
	int n, t, x;
	cin >> n >> t;
	for(int i=0; i<n; i++)
		cin >> times[i].first >> times[i].second;
	for(int i=0; i<n; i++) {
		if(times[i].first >= t) sr[i].first=times[i].first;
		else {
			x = ceil((t*1.0-times[i].first)/times[i].second);
			sr[i].first = times[i].first + x*times[i].second;
		}
		sr[i].second = i+1;
	}

	sort(sr, sr+n);
	cout << sr[0].second;

	return 0;
}
