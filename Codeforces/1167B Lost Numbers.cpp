#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int arr[] = {4, 8, 15, 16, 23, 42};
	map<int, pair<int, int> > mp;
	int n = 6;

	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			mp[arr[i]*arr[j]] = make_pair(arr[i], arr[j]);

	pair<int, int> q[] = {{1,2},{2,3},{3,4},{4,5}};
	int cnt[6][50]{}, rep[4], take[50]{}, ans[6]{}, x, a, b, qa, qb;

	for(int i=0; i<4; i++) {
		qa = q[i].first, qb = q[i].second;
		printf("? %d %d\n", qa, qb);
//		cout << "? " << qa << " " << qb;
        fflush(stdout);

        scanf("%d", &x);
//        cin >> x;
        rep[i]=x;
        a = mp[x].first, b = mp[x].second;
        cnt[qa-1][a]++, cnt[qa-1][b]++;
        cnt[qb-1][a]++, cnt[qb-1][b]++;
	}

	for(int i=0; i<6; i++) {
		for(int j=0; j<6; j++) {
			if(cnt[i][arr[j]] == 2) ans[i] = arr[j], take[arr[j]]=1;
		}
	}

	x = rep[0]/ans[1]; take[x]=1, ans[0]=x;
	x = rep[3]/ans[3]; take[x]=1, ans[4]=x;
	for(int j=0; j<6; j++) if(!take[arr[j]]) ans[5]=arr[j];

	printf("! %d %d %d %d %d %d\n", ans[0], ans[1], ans[2], ans[3], ans[4], ans[5]);
	fflush(stdout);

	return 0;
}







