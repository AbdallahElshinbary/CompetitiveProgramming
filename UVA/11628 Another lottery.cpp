#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,m,x,a,b,g,sum;
	int arr[10005];
	while(cin >> n >> m && n) {
		sum = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m-1; j++) cin >> x;
			cin >> arr[i];
			sum += arr[i];
		}
		for(int i=0; i<n; i++) {
			a=arr[i], b=sum;
			g = __gcd(a,b);
			a/=g, b/=g;
			printf("%d / %d\n", a,b);
		}
	}

	return 0;
}
