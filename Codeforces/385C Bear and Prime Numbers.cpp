#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 10000005;
int cnt[MAX], fp[MAX];
bool vis[MAX];

int main() {
	int n, m, x, a, b;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &x);
		cnt[x]++;
	}

	for(int i=2; i < MAX; i++) {
		fp[i] = fp[i-1];
		if(vis[i]) continue;
		for(int j=i; j<MAX; j += i) {
			vis[j]=true;
			fp[i] += cnt[j];
		}
	}

	cin >> m;
	while(m--) {
		cin >> a >> b;
		a = min(a, MAX-1);
		b = min(b, MAX-1);
		printf("%d\n", fp[b]-fp[a-1]);
	}

	return 0;
}

