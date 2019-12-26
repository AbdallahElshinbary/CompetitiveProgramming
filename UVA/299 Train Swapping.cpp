#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t,n,ans;
	int arr[55];
	cin >> t;
	while(t--) {
		cin >> n; ans=0;
		for(int i=0; i<n; i++) cin >> arr[i];
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				if(arr[i] > arr[j]) {ans++; swap(arr[i], arr[j]);}
		printf("Optimal train swapping takes %d swaps.\n", ans);
	}

	return 0;
}



