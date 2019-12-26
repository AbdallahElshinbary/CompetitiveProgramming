#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
	int t,r,h;
	while(cin >> t >> r >> h) {
		int pt[t][r+1], pr[r][h+1], ph[h][t+1];

		for(int i=0; i<t; i++)
			for(int j=0; j<r+1; j++)
				cin >> pt[i][j];
		for(int i=0; i<r; i++)
			for(int j=0; j<h+1; j++)
				cin >> pr[i][j];
		for(int i=0; i<h; i++)
			for(int j=0; j<t+1; j++)
				cin >> ph[i][j];


		int at=0, ar=0, ah=0;
		int a,b,c;

		bool nt[t]{}, nr[r]{}, nh[h]{};
		int res = INT_MAX;
		for(int i=0; i<t; i++) {
			int tmp = pt[i][0];
			for(int j=1; j<r+1; j++) {
				if(!pt[i][j]) {
					for(int k=1; k<h+1; k++) {
						if(!pr[j-1][k] && !ph[k-1][i+1]) {
							nt[i]=nr[j-1]=nh[k-1]=true;
							if(res > tmp + pr[j-1][0] + ph[k-1][0]) {
								res = tmp + pr[j-1][0] + ph[k-1][0];
								a = i, b=j-1, c=k-1;
							}
						}
					}
				}
			}
		}

		for(bool x : nt) at+=x;
		for(bool x : nr) ar+=x;
		for(bool x : nh) ah+=x;
		if(res == INT_MAX)
			cout << "Don't get married!\n";
		else
			cout << a << " " << b << " " << c << ":" << res << "\n";
	}

	return 0;
}
