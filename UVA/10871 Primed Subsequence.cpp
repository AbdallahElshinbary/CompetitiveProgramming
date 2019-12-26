#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000005;
bool prime[MAX];
vector<int> primes;
int arr[10005];

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

	int t,n;
	cin >> t;
	while(t--) {
		cin >> n;
		int x, l=n+1, tl;
		bool done=false;
		vector<int> ans, temp;
		for(int i=0; i<n; i++) cin >> arr[i];

		for(int i=0; i<n; i++) {
			x = arr[i], tl=1;
			temp.push_back(arr[i]);
			for(int j=i+1; j<n; j++) {
				x += arr[j], tl++;
				temp.push_back(arr[j]);
				if(prime[x]) {
					if(tl < l) ans=temp, l=tl;
					if(l == 2) done=true;
					break;
				}
			}
			if(done) break;
			temp.clear();
		}
		if(l == n+1) cout << "This sequence is anti-primed.\n";
		else {
			cout << "Shortest primed subsequence is length " << l << ":";
			for(int x : ans) cout << " " << x;
			cout << "\n";
		}
	}

	return 0;
}
