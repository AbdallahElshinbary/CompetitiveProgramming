#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int a,b;
	int p[4], mods[31417]{};

	for(int i=0; i<4; i++) cin >> p[i];
	cin >> a >> b;
	sort(p, p+4);

	do {
		for(int i=a; i<=b; i++)
			if((((i%p[0])%p[1])%p[2])%p[3] == i) mods[i]++;
	} while(next_permutation(p, p+4));

	int ans = 0;
	for(int i=a; i<=b; i++)
		if(mods[i] >= 7) ans++;
	cout << ans;

	return 0;
}

