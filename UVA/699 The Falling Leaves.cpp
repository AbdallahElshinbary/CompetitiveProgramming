#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<int, int> mp;
int l, r;

void go(int x, int offset) {
	mp[offset] += x;
	cin >> l;
	if(l != -1) go(l, offset-1);
	cin >> r;
	if(r != -1) go(r, offset+1);
}

int main() {
	int t=1, x;
	while(cin >> x && x != -1) {
		mp.clear(); go(x, 0);

		printf("Case %d:\n", t++);
		printf("%d", mp.begin()->second);
		for(auto it=++mp.begin(); it != mp.end(); it++) printf(" %d", it->second);
		printf("\n\n");
	}
	return 0;
}
