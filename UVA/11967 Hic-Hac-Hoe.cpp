#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,n,k,x,y,z,f,a,b,c,d,w;
	cin >> t;
	for(int T=1; T<=t; T++) {
		cin >> n >> k; f=1, w=-1;
		map<pair<int, int>, int> mp;
		while(n--) {cin >> x >> y; mp[{x,y}] = (f?1:2); f=!f;}
		for(auto m : mp) {
			x = m.first.first, y = m.first.second, z = m.second;
			a = 1;
			for(int i=1; i<k; i++) a += ((mp.find(pair<int, int>{x+i,y}) != mp.end()) ? (mp[{x+i,y}] == z) : 0);
			b = 1;
			for(int i=1; i<k; i++) b += ((mp.find(pair<int, int>{x,y+i}) != mp.end()) ? (mp[{x,y+i}] == z) : 0);
			c = 1;
			for(int i=1; i<k; i++) c += ((mp.find(pair<int, int>{x+i,y+i}) != mp.end()) ? (mp[{x+i,y+i}] == z) : 0);
			d = 1;
			for(int i=1; i<k; i++) d += ((mp.find(pair<int, int>{x-i,y+i}) != mp.end()) ? (mp[{x-i,y+i}] == z) : 0);

			if(a == k || b == k || c == k || d == k) {
				if(w != -1 && z != w) {w = 3; break;}
				else w = z;
			}
		}

		printf("Case %d: ", T);
		if(w == 1) printf("crosses\n");
		else if(w == 2) printf("noughts\n");
		else if(w == 3) printf("error\n");
		else if(w == -1) printf("none\n");
	}

	return 0;
}



