#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,m,x,o1=0,e1=0,o2=0,e2=0;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> x;
		if(x%2) o1++;
		else e1++;
	}
	for(int i=0; i<m; i++) {
		cin >> x;
		if(x%2) o2++;
		else e2++;
	}
	cout << min(o1,e2) + min(o2,e1);

	return 0;
}


















