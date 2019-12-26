#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

bool taken[20]{};
bool isprime[32]{};
vector<int> v;
int n;

void solve(int i, int cnt) {
	if(cnt == n && isprime[i+1]) {
		cout << 1;
		for(int i=1; i<(int)v.size(); i++) cout << " " << v[i];
		cout << "\n";
	}

	for(int x=2; x<=n; x++) {
		if(taken[x]) continue;
		if(isprime[i+x]) {
			taken[x]=true;
			v.push_back(x);
			solve(x, cnt+1);
			taken[x]=false;
			v.pop_back();
		}
	}
}

int main() {
	isprime[2]=isprime[3]=isprime[5]=isprime[7]=isprime[11]=isprime[13]=isprime[17]=isprime[19]=isprime[23]=isprime[29]=isprime[31]=true;
	int t=0;
	v.push_back(1);
	while(cin >> n) {
		if(t) printf("\n");
		printf("Case %d:\n", ++t);
		solve(1, 1);
	}

	return 0;
}
