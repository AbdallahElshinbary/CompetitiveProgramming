#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int killed[1025][1025];

int idx[] = {0,0,1,1,1,-1,-1,-1};
int idy[] = {1,-1,0,1,-1,0,1,-1};

void swipe(int i, int j, int k, int d) {
	int sx = max(i-d, 0), sy = max(j-d, 0);
	int ex = min(i+d, 1024), ey = min(j+d, 1024);

	for(int s=sx; s<=ex; s++)
		for(int e=sy; e<=ey; e++)
			killed[s][e] += k;
}

int main() {
	int t,n,d,a,b,c,cnt;
	pair<int,int> ans;
	cin >> t;
	while(t--) {
		memset(killed, 0, sizeof killed);

		cin >> d >> n;
		while(n--) {
			cin >> a >> b >> c;
			swipe(a, b, c, d);
		}

		cnt = -1;
		for(int i=0; i<1025; i++) {
			for(int j=0; j<1025; j++) {
				if(cnt < killed[i][j]) cnt=killed[i][j], ans={i,j};
				else if(cnt == killed[i][j]) {
					if(ans.first > i) ans={i,j};
					else if(ans.first == i) ans={i, min(ans.second, j)};
				}
			}
		}
		printf("%d %d %d\n", ans.first, ans.second, cnt);
	}


	return 0;
}
