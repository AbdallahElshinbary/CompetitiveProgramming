#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,s=0,a,x,cnt,ans;
	char arr[100005];
	int freq[150]{};
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		if(!freq[int(arr[i])]) freq[(int)arr[i]]++, s++;
	}
	memset(freq, 0, sizeof freq);

	a=cnt=0, ans=1e9;
	for(int i=0; i<n; i++) {
		if((++freq[int(arr[i])]) == 1) cnt++;
		if(cnt == s) {
			x= i-a+1;
			while(cnt == s) {
				if((--freq[(int)arr[a]]) == 0) cnt--;
				a++, x--;
			}
			ans = min(ans, x+1);
		}
	}
	cout << (ans == 1e9 ? 0 : ans) << "\n";

	return 0;
}
