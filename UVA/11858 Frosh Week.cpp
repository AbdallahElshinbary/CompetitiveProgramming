#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans;

void merge(int arr[], int start, int mid, int end) {
	int temp[end-start+1];
	int p=start, q=mid+1, k=0;

	for(int i=start; i<=end; i++) {
		if(p > mid)
			temp[k++] = arr[q++];
		else if(q > end)
			temp[k++] = arr[p++];
		else if(arr[p] < arr[q])
			temp[k++] = arr[p++];
		else
			temp[k++] = arr[q++], ans += mid-p+1;
	}

	for(int i=0; i<k; i++)
		arr[start++] = temp[i];
}

void merge_sort(int arr[], int start, int end) {
	if(start < end) {
		int mid = (start+end)/2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int main() {
	int n;
	int arr[1000005];
	while(cin >> n && n) {
		ans = 0;
		for(int i=0; i<n; i++) cin >> arr[i];
		merge_sort(arr, 0, n-1);
		cout << ans << "\n";
	}

	return 0;
}



