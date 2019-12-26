#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	int a[105][105], r[105], c[105];
	while(cin >> n && n) {
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin >> a[i][j];

		memset(r, 0, sizeof r);
		memset(c, 0, sizeof c);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				r[i] += a[i][j];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				c[i] += a[j][i];

		int cnt=0, t;
		for(int i=0; i<n; i++) {
			cnt += (r[i]%2) + (c[i]%2);
		}
		if(!cnt) {printf("%s", "OK\n"); continue;}

		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				t = cnt;
				t -= (r[i]%2) + (c[j]%2);
				if(t == 0) {printf("Change bit (%d,%d)\n", i+1, j+1); cnt=0; break;}
			}
			if(cnt == 0) break;
		}

		if(cnt) printf("%s", "Corrupt\n");
	}

	return 0;
}
