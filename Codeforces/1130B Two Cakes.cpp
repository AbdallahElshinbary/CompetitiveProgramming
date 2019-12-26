#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, x, y;
	cin >> n;
	pair<int, int> pos[n+1]{};

	for(int i=1; i<=2*n; i++) {
		cin >> x;
		if(!pos[x].first) pos[x].first = i;
		else pos[x].second = i;
	}

	ll a=pos[n].first, b=pos[n].second, sa=0, sb=0;

	for(int i=n-1; i>=1; i--) {
		x = pos[i].first, y = pos[i].second;
		if(abs(a-x)+abs(b-y) < abs(a-y)+abs(b-x)) {
			sa += abs(a-x), sb += abs(b-y);
			a=x, b=y;
		} else {
			sa += abs(a-y), sb += abs(b-x);
			a=y, b=x;
		}
	}

	cout << sa + sb + pos[1].first + pos[1].second - 2;

	return 0;
}
