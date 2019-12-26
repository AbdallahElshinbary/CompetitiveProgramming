#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,k,l=-1, r=-1,cnt=0;
	int arr[100005], freq[100005]{};
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		if(freq[arr[i]]++ == 0) cnt++;
		if(cnt == k) {l=0, r=i; break;}
	}
	if(l == -1) {cout << l << " " << r; return 0;}

	while(1) {
		freq[arr[l]]--;
		if(freq[arr[l]] == 0) {freq[arr[l]]++; break;}
		l++;
	}

	while(1) {
		freq[arr[r]]--;
		if(freq[arr[r]] == 0) {freq[arr[r]]++; break;}
		r--;
	}

	cout << l+1 << " " << r+1 << "\n";

	return 0;
}







