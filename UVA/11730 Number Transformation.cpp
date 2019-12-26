#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T=1, s, t, x;
const int MAX = 1005;
bool prime[MAX];
vector<int> primes;
int dp[MAX];

void sieve() {
	fill(prime+2, prime+MAX, 1);
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i])
			for(int j=i*2; j<MAX; j+=i) prime[j] = 0;
	}
	for(int i=2; i<MAX; i++) if(prime[i]) primes.push_back(i);
}

int dfs(int n) {
	if(n > t) return 1e9;
	if(n == t) return 0;

	int &ret = dp[n];
	if(ret != -1) return ret;
	ret = 1e9;

	for(int x : primes) {
		if(x >= n) break;
		if(n%x == 0) {
			ret = min(ret, dfs(n+x)+1);
		}
	}
	return ret;
}

int main() {
	sieve();
	while(cin >> s >> t && s) {
		memset(dp, -1, sizeof dp);
		x = dfs(s);
		printf("Case %d: ", T++);
		if(x != 1e9) printf("%d\n", x);
		else printf("-1\n");
	}
	return 0;
}
