#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int x, y, ans=0;
	cin >> x >> y;
	int arr[3] = {y,y,y};
	while(true) {
		sort(arr, arr+3);
		arr[0] = min(x, arr[1]+arr[2]-1);
		ans++;
		if(arr[0]==x && arr[1]==x && arr[2]==x) break;
	}
	cout << ans;

	return 0;
}
