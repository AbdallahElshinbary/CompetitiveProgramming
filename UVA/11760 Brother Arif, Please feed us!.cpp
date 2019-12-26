#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int R,C,N,x,y,tx,ty,t=1;
bool r[100005];
bool c[100005];
int dx[] = {0,0,0,1,-1};
int dy[] = {0,1,-1,0,0};

bool valid(int x, int y) {
	return (x >= 0 && x < R && y >= 0 && y < C);
}

int main() {
	while(cin >> R >> C >> N && R) {
		memset(r, 0, sizeof r);
		memset(c, 0, sizeof c);
		for(int i=0; i<N; i++) {
			cin >> x >> y;
			r[x] = 1, c[y] = 1;
		}
		cin >> x >> y;
		bool ok=0;
		for(int i=0; i<5; i++) {
			tx=x+dx[i], ty=y+dy[i];
			if(valid(tx,ty) && !r[tx] && !c[ty]) {ok=1; break;}
		}
		if(ok) printf("Case %d: Escaped again! More 2D grid problems!\n", t++);
		else printf("Case %d: Party time! Let's find a restaurant!\n", t++);
	}

	return 0;
}



