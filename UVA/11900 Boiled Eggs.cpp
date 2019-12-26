#include <bits/stdc++.h>
using namespace std;

int main() {
	int T,n,P,Q;
	cin >> T;
	for(int t=1; t<=T; t++) {
		cin >> n >> P >> Q;
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];
		sort(arr, arr+n);

		cout << "Case " << t << ": ";
		int i=0, cnt=0, grams=0;
		for(int i=0; i<n; i++)
			if(grams+arr[i] <= Q && cnt+1 <= P)
				grams+= arr[i], cnt++;

		cout << cnt << "\n";
	}

	return 0;
}

