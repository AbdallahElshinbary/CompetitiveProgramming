#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e12
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,cnt=0,x,all=0;
	int arr[105];
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	cnt = x = arr[0];
	vector<int> v;
	v.push_back(1);

	for(int i=0; i<n; i++) {
		all += arr[i];
		if(2*arr[i] <= x) cnt += arr[i], v.push_back(i+1);
	}

	if(cnt*2 > all) {
		cout << v.size() << "\n";
		for(int x : v) cout << x << " ";
	} else {
		cout << 0;
	}


	return 0;
}




















