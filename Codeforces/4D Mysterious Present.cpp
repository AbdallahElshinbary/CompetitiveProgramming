#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,w,h,x,y;
	pair<pair<int, int>, int> arr[5005];
	cin >> n >> w >> h;
	for(int i=0; i<n; i++) {
		cin >> arr[i].first.first >> arr[i].first.second;
		arr[i].second = i+1;
	}
	sort(arr, arr+n);

	int L[5005]{};
	for(int i=0; i<n; i++) {
		x = arr[i].first.first, y = arr[i].first.second;
		if(x <= w || y <= h) continue;
		L[i] = 1;
		for(int j=0; j<i; j++)
			if(arr[j].first.first < x && arr[j].first.second < y)
				L[i] = max(L[i], 1+L[j]);
	}

	int mx = 0, cur;
	for(int i=0; i<n; i++)
		if(mx < L[i]) mx = L[i], cur=i;
	cout << mx << "\n";
	if(!mx) return 0;

	vector<int> ans; ans.push_back(arr[cur].second); mx--;
	for(int i=cur-1; i>=0; i--) {
		if(!mx) break;
		if(L[i] == mx && arr[i].first.first < arr[cur].first.first && arr[i].first.second < arr[cur].first.second) {
			ans.push_back(arr[i].second); cur=i, mx--;
		}
	}
	for(int i=(int)ans.size()-1; i>=0; i--)
		cout << ans[i] << " ";


	return 0;
}





























