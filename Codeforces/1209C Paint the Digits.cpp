#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-6
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t,n,cur;
	string s;
	int arr[200005], cnt[10], ans[200005];
	cin >> t;
	while(t--) {
		cin >> n >> s;
		memset(cnt, 0, sizeof cnt);
		for(int i=0; i<n; i++) {arr[i] = s[i]-'0'; cnt[arr[i]]++;}

		cur = 0;
		for(int x=0; x<2; x++) {
			for(int i=0; i<n; i++) {
				while(!cnt[cur]) cur++;
				if(arr[i] == cur) {cnt[cur]--; ans[i]=x+1;}
			}
		}

		bool flag=1;
		for(int i=0; i<10; i++) if(cnt[i] != 0) flag=0;
		if(!flag) {cout << "-\n"; continue;}
		for(int i=0; i<n; i++) cout << ans[i];
		cout << "\n";
	}

	return 0;
}






















