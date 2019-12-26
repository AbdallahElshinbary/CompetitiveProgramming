#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	double arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];

	double x;
	int s;
	for(int d=-1000; d<=1000; d++) {
		if(d == 0) continue;
		s = 0;
		for(int i=0; i<n; i++) {
			x = arr[i]/d;
			if(x > 0) s++;
		}
		if(s >= ceil(n*1.0/2)) {cout << d; return 0;}
	}
	cout << 0;


	return 0;
}
