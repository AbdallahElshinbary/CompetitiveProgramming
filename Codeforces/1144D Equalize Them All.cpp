#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, mx=-1, m;
	int arr[200005], freq[200005]{};
	vector<int> pl;

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		if(mx < ++freq[arr[i]]) mx = freq[arr[i]], m=arr[i];
	}

	printf("%d\n", n-freq[m]);
	for(int i=0; i<n; i++) if(arr[i]==m) pl.push_back(i);
	for(int x : pl) {
		for(int i=x-1; i>=0; i--) {
			if(arr[i] == m) break;
			if(arr[i] < m) printf("%d %d %d\n", 1, (i)+1, (i+1)+1);
			else printf("%d %d %d\n", 2, (i)+1, (i+1)+1);
			arr[i] = m;
		}

		for(int i=x+1; i<n; i++) {
			if(arr[i] == m) break;
			if(arr[i] < m) printf("%d %d %d\n", 1, (i)+1, (i-1)+1);
			else printf("%d %d %d\n", 2, (i)+1, (i-1)+1);
			arr[i] = m;
		}
	}

	return 0;
}
