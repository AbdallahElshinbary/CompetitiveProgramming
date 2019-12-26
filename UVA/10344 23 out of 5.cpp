#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int arr[5];
bool used[5];

bool rec(int n, int sum) {
	if(n == 5 && sum == 23)
		return true;

	for(int i=0; i<5; i++) {
		if(used[i]) continue;
		used[i] = true;
		if(rec(n+1, sum+arr[i])) return true;
		if(rec(n+1, sum-arr[i])) return true;
		if(rec(n+1, sum*arr[i])) return true;
		used[i]=false;

	}
	return false;
}

int main() {
	while(cin >> arr[0] && arr[0]) {
		for(int i=1; i<5; i++) cin >> arr[i];
		memset(used, 0, sizeof used);
		bool flag = false;
		for(int i=0; i<5; i++) {
			used[i]=true;
			if(rec(1, arr[i])) {
				flag = true;
				break;
			}
			used[i]=false;
		}
		cout << (flag ? "Possible\n" : "Impossible\n");
	}
	return 0;
}
