#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000002;
ll inc[MAX], ans[MAX];

int main() {
	int n, cnt=1;

	inc[3]=0;
	for(int i=4; i<MAX-1; i+=2) {
		inc[i] = inc[i-1]+cnt;
		inc[i+1] = inc[i]+cnt;
		cnt++;
	}
	for(int i=4; i<MAX-1; i++) ans[i] = ans[i-1]+inc[i];

	while(cin >> n && n>=3) cout << ans[n] << "\n";

	return 0;
}
