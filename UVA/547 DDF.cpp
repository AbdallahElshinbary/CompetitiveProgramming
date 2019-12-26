#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 3005;
int nex[MAX], len[MAX];

int num(int n) {
	int ans = 0;
	while(n) ans += n%10, n/=10;
	return ans;
}

int sum(int n) {
	int i, ans = 0;
	for(i=1; i*i<n; i++)
		if(n%i == 0) ans += num(i) + num(n/i);
	if(i*i == n) ans += num(i);
	return ans;
}

int cal(int n) {
	if(len[n] != -1) return len[n];
	if(nex[n] == n) return len[n] = 1;
	return len[n] = 1 + cal(nex[n]);
}

int main() {
	for(int i=1; i<MAX; i++) nex[i] = sum(i);

	memset(len, -1, sizeof len);
	for(int i=1; i<MAX; i++) {
		if(len[i] != -1) continue;
		cal(i);
	}

	int t=1, n, m, x, mx;
	while(cin >> n >> m && n <= 3000) {
		printf("Input%d: %d %d\n", t, n, m);
		if(n > m) swap(n, m);
		mx=0;
		for(int i=n; i<=m; i++)
			if(len[i] > mx) mx=len[i], x=i;
		printf("Output%d:", t++);
		while(true) {
			if(nex[x] == x) {printf(" %d", x); break;}
			printf(" %d", x); x = nex[x];
		}
		cout << "\n";
	}

	return 0;
}
