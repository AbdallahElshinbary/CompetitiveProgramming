#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int check(string &a, string &b) {
	int sa = (int)a.size(), sb = (int)b.size();
	int x = 0, temp;

	int ia=0, ib=0;
	while(ia < sa) {
		temp=0;
		for(int i=ia, j=ib; i<sa && j<sb; i++, j++)
			if(a[i] == b[j]) temp++;
		x = max(x, temp);
		ia++;
	}

	ia=0, ib=sb-1;
	while(ib >= 0) {
		temp=0;
		for(int i=ia, j=ib; i<sa && j<sb; i++, j++)
			if(a[i] == b[j]) temp++;
		x = max(x, temp);
		ib--;
	}

	return x;
}

int main() {
	int t,n,ans;
	cin >> t;
	while(t--) {
		ans = 0;
		cin >> n;
		string arr[n];
		for(int i=0; i<n; i++) cin >> arr[i];

		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				ans = max(ans, check(arr[i], arr[j]));

		cout << ans << "\n";
	}

	return 0;
}
