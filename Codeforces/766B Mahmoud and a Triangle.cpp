#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define INF 1e12
#define EPS 1e-9
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int arr[100005];
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);
	for(int i=0; i<n-2; i++)
		if(arr[i]+arr[i+1] > arr[i+2]) {cout << "YES"; return 0;}
	cout << "NO";

	return 0;
}




















