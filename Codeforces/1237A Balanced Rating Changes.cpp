#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define INF 1e9
#define EPS 1e-6
#define PI acos(-1)
#define mp make_pair
#define sz(s) (int)s.size()

void print(int x) {
	if(x < 0) cout << (x-1)/2 << "\n";
	else cout << (x+1)/2 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,a=0,b=0;
	int arr[100005];
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
		if(arr[i] > 0 && (arr[i]&1)) a++;
		else if(arr[i] < 0 && (arr[i]&1)) b++;
	}
	a /= 2, b /= 2;

	for(int i=0; i<n; i++) {
		if(arr[i]&1) {
			if(arr[i] > 0) {
				if(!a) print(arr[i]);
				else {cout << arr[i]/2 << "\n"; a--;}
			} else {
				if(!b) print(arr[i]);
				else {cout << arr[i]/2 << "\n"; b--;}
			}
		} else cout << arr[i]/2 << "\n";
	}

	return 0;
}


















