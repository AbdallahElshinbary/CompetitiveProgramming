#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n,ans;
	int arr[1005];
	while(cin >> n) {
		ans=0;
		for(int i=0; i<n; i++) cin >> arr[i];

		bool flag;
		while(1) {
			flag=0;
			for(int i=0; i<n-1; i++)
				if(arr[i] > arr[i+1]) {swap(arr[i], arr[i+1]); ans++, flag=1;}
			if(!flag) break;
		}

		printf("Minimum exchange operations : %d\n", ans);
	}

	return 0;
}



