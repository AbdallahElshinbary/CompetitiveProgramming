#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int arr[4];
	int a,b,c;
	for(int i=0; i<4; i++) cin >> arr[i];
	sort(arr, arr+4);
	a = (arr[0]+arr[1]-arr[2])/2;
	b = arr[0]-a;
	c = arr[1]-a;
	printf("%d %d %d",a,b,c);

	return 0;
}
