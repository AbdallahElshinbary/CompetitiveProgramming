#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n, x, pos, prev, num, curr;
	while(cin >> n) {
		prev = n-2; //the previous line count
		pos = (prev)/2 + 1; //position in odd numbers
		num = pos*(1+prev)/2; //count of odds from 1 to previous
		curr = num + n; //last in line
		x = curr*2 - 1;
		cout << x + (x-2) + (x-4) << "\n";
	}
	return 0;
}
