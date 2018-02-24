#include <bits/stdc++.h>
using namespace std;

int n, used[17], res=0;
bool isprime[50];
vector<int> v;

void solve(int curr, int cnt) {
	if(cnt == n && isprime[curr+1]) {
		cout << 1;
        for(int i : v)
        	cout << " " << i;
        cout << "\n";
		return;
	}

	for(int i=2; i<=n; i++) {
		if(!used[i] && isprime[curr+i]) {
			used[i] = true;
			v.push_back(i);
			solve(i, cnt+1);
			used[i] = false;
			v.pop_back();
		}
	}
}

int main() {
	for(int i=0; i<50; i++)
		isprime[i] = true;
	isprime[0] = isprime[1] = false;
	for(int i=2; i<50; i++) {
		if(isprime[i]) {
			for(int j=i*2; j<50; j+=i)
				isprime[j] = false;
		}
	}

	int x=0;
	while(cin >> n) {
		x++;
        if(x > 1)
        	cout << "\n";
        cout << "Case " << x << ":\n";
        memset(used, 0, sizeof(used));
		solve(1, 1);
	}

	return 0;
}

