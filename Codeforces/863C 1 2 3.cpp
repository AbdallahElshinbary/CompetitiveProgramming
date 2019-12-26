#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	map<pair<ll, ll>, ll> mp;
	map<pair<ll, ll>, pair<ll, ll> > score;
	map<pair<ll, ll>, ll> pos;
	ll k;
	ll a, b, m, dx, dy, c, f;
	bool wx=false, wy=false, cycle=false;
	cin >> k >> a >> b;

	int alice[3][3], bob[3][3];
	for(int i=0; i<3; i++) for(int j=0; j<3; j++) cin >> alice[i][j];
	for(int i=0; i<3; i++) for(int j=0; j<3; j++) cin >> bob[i][j];

	ll x=0,y=0, ta,tb;
	for(ll i=0; i<k; i++) {
		if((a == 3 && b == 2) || (a == 2 && b == 1) || (a == 1 && b == 3)) x++, wx=true, wy=false;
		else if(a != b) y++, wx=false, wy=true;
		else wx=false, wy=false;

		mp[{a,b}]++;
		if(mp[{a,b}] == 2) {
			cycle = true;
			m = i-pos[{a,b}];
			dx = x-score[{a,b}].first, dy = y-score[{a,b}].second;
			c = (k - pos[{a,b}]) / m;
			f = i, ta=a, tb=b;
			if(wx) x--;
			else if(wy) y--;
			break;
		}

		pos[{a,b}] = i;
		score[{a,b}] = {x,y};

		ta = a, tb = b;
		a = alice[ta-1][tb-1];
		b = bob[ta-1][tb-1];
	}

	if(cycle) {
		c = max(0LL, c-1);
		x += dx*c, y += dy*c;

		f += c*m, a=ta, b=tb;
		for(ll i=f; i<k; i++) {
			if((a == 3 && b == 2) || (a == 2 && b == 1) || (a == 1 && b == 3)) x++;
			else if(a != b) y++;
			ta = a, tb = b;
			a = alice[ta-1][tb-1];
			b = bob[ta-1][tb-1];
		}
	}

	cout << x << " " << y;

	return 0;
}
