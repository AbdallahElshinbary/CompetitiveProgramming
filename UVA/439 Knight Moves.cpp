#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

vector<vector<int> > adj(65, vector<int>(65, INF));
int dx[] = {1,1,2,2};
int dy[] = {2,-2,1,-1};

bool valid(int x, int y) {
	return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

void conn(int x, int y) {
	for(int i=0; i<4; i++) {
		int tx=x+dx[i], ty=y+dy[i];
		if(valid(tx,ty)) adj[x*8+y][tx*8+ty] = adj[tx*8+ty][x*8+y] = 1;
	}
}

int main() {
	char a,b,c,d;
	int x1,y1,x2,y2;

	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			conn(i, j);

	for(int k=0; k<64; k++)
		for(int i=0; i<64; i++)
			for(int j=0; j<64; j++)
				adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

	while(cin >> a >> b >> c >> d) {
		x1=a-'a', y1=b-'1', x2=c-'a', y2=d-'1';
		printf("To get from %c%c to %c%c takes %d knight moves.\n", a,b,c,d, (a==c && b==d ? 0 : adj[x1*8+y1][x2*8+y2]));
	}

	return 0;
}