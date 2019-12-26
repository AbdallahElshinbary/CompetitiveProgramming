#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000005;
bool prime[MAX];
vector<int> primes;
int query[1000005];

bool circular(int n) {
	string s = to_string(n);
	char c;
	for(int i=0; i<(int)s.size(); i++) {
		c = s.back();
		s.pop_back();
		reverse(s.begin(), s.end());
		s.push_back(c);
		reverse(s.begin(), s.end());
		if(!prime[stoi(s)]) return false;
	}
	return true;
}

void sieve() {
	prime[0] = prime[1] = false;
	for(int i=2; i*i<=MAX; i++) {
		if(prime[i])
			for(int j=2*i; j<MAX; j+=i) prime[j]=false;
	}
	for(int i=0; i<MAX; i++)
		if(prime[i]) primes.push_back(i);
}

int main() {
	for(int i=0; i<MAX; i++) prime[i]=true;
	sieve();

	int c=0;
	for(int i=0; i<1000003; i++) {
		if(prime[i] && circular(i)) c++;
		query[i] = c;
	}

	int a,b,q;
	while(cin >> a && a != -1) {
		cin >> b;
		q = query[b]-query[a-1];
		if(q) cout << q << (q == 1 ? " Circular Prime.\n" : " Circular Primes.\n");
		else cout << "No Circular Primes.\n";
	}

	return 0;
}
