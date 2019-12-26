#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

vector<int> ans, temp;
bool used[22];
int arr[22];
int n, m, x=0;

void solve(int left, int j) {
	if(x < n-left) {
		x=n-left, ans = temp;
		if(x == n) return;
	}
	for(int i=j; i<m; i++) {
		if(arr[i]>left) continue;
		temp.push_back(arr[i]);
		solve(left-arr[i], i+1);
		temp.pop_back();
	}
}

int main() {
	while(cin >> n >> m) {
		x=0;
		for(int i=0; i<m; i++) cin >> arr[i];
		solve(n, 0);
		for(auto i : ans) cout << i << " ";
		cout << "sum:" << x << "\n";
	}
	return 0;
}
