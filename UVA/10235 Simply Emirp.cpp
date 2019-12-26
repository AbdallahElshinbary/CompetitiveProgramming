#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000005;
bool prime[MAX];

void sieve() {
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i])
			for(int j=2*i; j<MAX; j+=i) prime[j]=false;
	}
}

int rev(int n) {
	string s = to_string(n);
	reverse(s.begin(), s.end());
	return stoi(s);
}

int main() {
	fill(prime+2, prime+MAX, true);
	sieve();

	int n;
	while(cin >> n) {
		if(prime[n]) {
			if(rev(n) != n && prime[rev(n)]) printf("%d is emirp.\n", n);
			else printf("%d is prime.\n", n);
		} else {
			printf("%d is not prime.\n", n);
		}
	}

	return 0;
}
