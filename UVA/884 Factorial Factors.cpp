#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int arr[1000005];

int fact(int n) {
	int ans = 0;
	for(int i=2; i*i<=n; i++) {
		while(n%i == 0) n/=i, ans++;
	}
	if(n > 1) ans++;
	return ans;
}

int main() {
	arr[1]=0;
	for(int i=2; i<=1000000; i++) {
		arr[i] = fact(i)+arr[i-1];
	}

	int n;
	while(scanf("%d", &n) != EOF)
		printf("%d\n", arr[n]);


	return 0;
}
