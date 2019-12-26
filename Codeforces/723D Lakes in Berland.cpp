#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char grid[55][55];
bool vis[55][55];
int n,m,k,x,y,tx,ty,cnt,oc,ans=0;
vector<pair<int, pair<int, int> > > lakes;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool valid(int i, int j) {return (i >= 0 && i < n && j >= 0 && j < m);}
bool ocean(int i, int j) {return (i == 0 || i == n-1 || j == 0 || j == m-1);}

void dfs(int x, int y) {
	vis[x][y] = 1; cnt++;
	if(ocean(x, y)) oc=1;
	for(int i=0; i<4; i++) {
		tx = x+dx[i], ty = y+dy[i];
		if(valid(tx, ty) && grid[tx][ty] == '.' && !vis[tx][ty]) dfs(tx, ty);
	}
}

void flood(int x, int y) {
	grid[x][y] = '*';
	for(int i=0; i<4; i++) {
		tx = x+dx[i], ty = y+dy[i];
		if(valid(tx, ty) && grid[tx][ty] == '.') flood(tx, ty);
	}
}

int main() {
	cin >> n >> m >> k;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> grid[i][j];

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(grid[i][j] == '.' && !vis[i][j]) {
				cnt = oc = 0; dfs(i, j);
				if(!oc) lakes.push_back(make_pair(cnt, make_pair(i,j)));
			}
		}
	}
	sort(lakes.begin(), lakes.end());

	int c=(int)lakes.size();
	for(auto x : lakes) {
		if(c-- == k) break;
		ans += x.first;
		flood(x.second.first, x.second.second);
	}

	cout << ans << "\n";
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			cout << grid[i][j];
		cout << "\n";
	}

	return 0;
}
