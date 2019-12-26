#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> ft;

int LSOne(int i) {return (i & (-i));}
int rsq(int b) {
    int sum = 0;
    for(; b; b -= LSOne(b)) sum += ft[b];
    return sum;
}
int rsq(int a, int b) {return rsq(b) - rsq(a-1);}
void adjust(int k, int v) {for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;}  //(v is inc/dec value)


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t=0,n,x,y;
	int arr[200005];
	string s;
	while(cin >> n && n) {
		ft.assign(n+1, 0);
		for(int i=1; i<=n; i++) {cin >> arr[i]; adjust(i, arr[i]);}

		if(t) cout << "\n";
		cout << "Case " << ++t << ":\n";

		while(cin >> s && s != "END") {
			cin >> x >> y;
			if(s == "S") {adjust(x, y-arr[x]); arr[x]=y;}
			else cout << rsq(x, y) << "\n";
		}
	}

	return 0;
}











