#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll h,n,x,ans=0;
	cin >> h >> n;
	x = powl(2, h);

	bool l1=1, l2;

	for(int i=0; i<h; i++) {
		if(n > x/2) l2=0, n -= x/2;
		else l2=1;
		x /= 2;

		ans++;
		if(l2 != l1) {
			for(int j=i+1; j<=h; j++) ans += powl(2, j-i-1);
			continue;
		}
		l1 = !l1;
	}
	cout << ans;

	return 0;
}




//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long ll;
//
//bool vis[100005];
//vector<vector<int> > adj;
//set<int> ss;
//map<int, int> in;
//int cnt;
//
//bool bfs(int r) {
//	queue<int> q; q.push(r); vis[r]=1;
//
//	while(!q.empty()) {
//		int u = q.front(); q.pop(); cnt++;
//		for(int x : adj[u]) {
//			if(vis[x]) return 0;
//			q.push(x);
//		}
//	}
//	return 1;
//}
//
//int main() {
//	int t=1,x,y;
//
//	while(1) {
//		adj.assign(100005, {});
//		ss.clear(); in.clear();
//
//		while(cin >> x >> y && x) {
//			if(x <= 0) return 0;
//			adj[x].push_back(y);
//			in[y]++; ss.insert(x); ss.insert(y);
//		}
//
//		printf("Case %d ", t++);
//		cnt = 0;
//		for(int x : ss)
//			if(in[x] == 0) {
//				if(!bfs(x) || cnt < (int)ss.size()) printf("is not a tree.\n");
//				else printf("is a tree.\n");
//			}
//	}
//
//	return 0;
//}
