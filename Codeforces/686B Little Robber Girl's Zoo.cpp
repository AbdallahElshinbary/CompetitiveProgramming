#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	int arr[105];
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];

	bool flag;
	while(1) {
		flag=0;
		for(int i=0; i<n-1; i++)
			if(arr[i] > arr[i+1]) {printf("%d %d\n", i+1,i+2); swap(arr[i], arr[i+1]); flag=1;}
		if(!flag) break;
	}

	return 0;
}



