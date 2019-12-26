#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,a,b,n,m,x;
	cin >> t;
	while(t--) {
		cin >> a >> b >> n >> m;
		x = pow(10, m);

		int period[] = {60, 300, 1500, 15000};

		int arr[period[m-1]];
		arr[0] = a%x, arr[1]=b%x;
		for(int i=2; i<period[m-1]; i++) {
			arr[i] = (arr[i-1]+arr[i-2])%x;
		}

		cout << arr[n%period[m-1]] << "\n";
	}

	return 0;
}
