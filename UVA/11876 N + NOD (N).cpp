#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100005;
int arr[MAX];

int NOD(int n) {
	int p, ans=1;
	for(int i=2; i*i<=n; i++) {
		p = 0;
		while(n%i == 0) n/=i, p++;
		ans *= (p+1);
	}
	if(n > 1) ans *= 2;
	return ans;
}

int main() {
	arr[0] = 1;
	for(int i=1; i<MAX; i++)
		arr[i] = arr[i-1] + NOD(arr[i-1]);

	int t,a,b,l,r;
	cin >> t;
	for(int T=1; T<=t; T++) {
		cin >> a >> b;
		l = lower_bound(arr, arr+MAX, a) - arr;
		r = lower_bound(arr, arr+MAX, b+1) - arr;
		printf("Case %d: %d\n", T, r-l);
	}

	return 0;
}
