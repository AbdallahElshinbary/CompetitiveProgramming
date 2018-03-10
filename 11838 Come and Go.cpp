#include <bits/stdc++.h>
using namespace std;

const int SIZE=2005;
vector<vector<int> > AdjList;
vector<int> v;
int num[SIZE], low[SIZE];
bool inStack[SIZE];
int cnt;


int SSC(int u) {
	num[u] = low[u] = ++cnt;
	inStack[u] = true;
	v.push_back(u);

	for(int x : AdjList[u]) {
		if(num[x] == -1)
			SSC(x);
		if(inStack[x])
			low[u] = min(low[u], low[x]);
	}

	int count=0;
	if(num[u] == low[u]) {
		while(1) {
			count++;
			int x = v.back();
			v.pop_back();
			inStack[x] = false;
			if(x == u)
				break;

		}
	}
	return count;
}

int main() {
	int n,m,x,y,z;
	while(cin >> n >> m && n && m) {
		AdjList.assign(SIZE, {});
		v.clear();
		memset(num, -1, sizeof num);
		memset(low, -1, sizeof low);
		memset(inStack, false, sizeof inStack);
		cnt = 0;

		while(m--) {
			cin >> x >> y >> z;
			AdjList[x].push_back(y);
			if(z == 2) AdjList[y].push_back(x);
		}
		cout << (SSC(1) == n) << "\n";
	}

	return 0;
}

