#include <bits/stdc++.h>
using namespace std;

int arr[50005];
int ans[50005];
bool vis[50005];

int dfs(int node) {
	int cnt = 1;
	vis[node] = true;
	if(arr[node] != -1 && !vis[arr[node]])
		cnt += dfs(arr[node]);
	vis[node] = false;
	ans[node] = cnt;
	return cnt;
}


int main() {
	int t,n,x,y,mx,idx;
	scanf("%d", &t);
	for(int T=1; T<=t; T++) {
		memset(arr, -1, sizeof arr);
		memset(ans, -1, sizeof ans);
		mx = -1;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d %d", &x, &y);
			arr[x] = y;
		}
		for(int i=1; i<=n; i++) {
			if(ans[i] == -1)
				dfs(i);
			if(mx < ans[i])
				mx = ans[i], idx = i;
		}
		printf("Case %d: %d\n", T, idx);
	}

	return 0;
}

