#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2000005;
bool prime[MAX];
int num[MAX], arr[MAX];

void sieve() {
	for(int i=2; i<MAX; i++) {
		if(prime[i]) {
			num[i]++;
			for(int j=i*2; j<MAX; j+=i) {
				prime[j] = false;
				int x = j;
				while(x%i==0) x/=i, num[j]++;
			}
		}
	}
}

bool cmp(int &a, int &b) {
	if(num[a] == num[b]) return a < b;
	return num[a] <= num[b];
}

int main() {
	fill(prime+2, prime+MAX, 1);
	sieve();

	num[1] = 1, num[0] = 1e9;
	for(int i=1; i<=MAX-5; i++) arr[i-1] = i;
	sort(arr, arr+MAX, cmp);

	int n, t=1;
	while(cin >> n && n) printf("Case %d: %d\n", t++, arr[n-1]);

	return 0;
}
