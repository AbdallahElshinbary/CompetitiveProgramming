#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
bool prime[100005];
int ans[100005];

void sieve() {
	int x = 1;
	for(int i=2; i<=n; i++) {
		if(prime[i]) {
			ans[i]=x;
			for(int j=2*i; j<=n; j +=i )
				ans[j]=x, prime[j]=0;
			x++;
		}
	}
}

int main() {
	fill(prime+2, prime+100005, true);

	cin >> n;
	sieve();
	for(int i=2; i<=n; i++)
		cout << ans[i] << " ";

	return 0;
}
