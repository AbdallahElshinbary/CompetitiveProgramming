#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t, n;
	vector<int> divs;
	cin >> t;
	while(t--) {
		cin >> n;
		if(n <= 1) {cout << n << "\n"; continue;}
		divs.clear();
		for(int i=9; i>1; i--) {
			while(n%i == 0) {
				divs.push_back(i);
				n /= i;
			}
		}
		if(n > 1) {cout << "-1\n"; continue;}
		for(int i=(int)divs.size()-1; i>=0; i--) cout << divs[i];
		cout << "\n";
	}

	return 0;
}
