#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sumDiv(int n) {
	int p = 0, ans=1;
	for(int i=2; i*i<=n; i++) {
		p = 0;
		while(n%i == 0) n/=i, p++;
		ans *= (pow(i, p+1)-1)/(i-1);
	}
	if(n > 1) ans *= (pow(n, 2)-1)/(n-1);
	return ans;
}

int main() {
	int arr[10000]{};
	for(int i=1; i<1000; i++) arr[sumDiv(i)] = i;

	int t=1, n;
	while(scanf("%d", &n) && n) {
		if(arr[n] == 0) printf("Case %d: -1\n", t++);
		else printf("Case %d: %d\n", t++, arr[n]);
	}

	return 0;
}
