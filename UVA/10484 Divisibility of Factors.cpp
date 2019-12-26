#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int freq[105];

bool prime(int n) {
	for(int i=2; i*i<=n; i++) if(n%i == 0) return false;
	return true;
}

void count(int n, int p) {
	int x = 0;
	for(int i=p; i<=n; i*=p) x += n/i;
	freq[p] = x;
}
int main() {
	int n,d;
	bool ok;
	while(scanf("%d %d", &n, &d) && d) {
		memset(freq, 0, sizeof freq);
		d = abs(d);
		ok = true;
		for(int i=2; i<=n; i++) if(prime(i)) count(n, i);
		for(int i=2; i*i<=d; i++) {
			if(i > n) {ok=false; break;}
			while(d%i == 0) {
				d/=i;
				freq[i]--;
			}
		}
		if(d > 1) {
			if(d > n) ok=false;
			else freq[d]--;
		}
		if(!ok) {cout << "0\n"; continue;}
		
		ll ans = 1;
		for(int x : freq) {
			if(x < 0) {ans=0; break;}
			ans *= x+1;
		}
		cout << ans << "\n";
	}

	return 0;
}
