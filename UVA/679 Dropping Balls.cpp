#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int MAX;

int BS(int node, int balls) {
	int left = node*2, right = left+1;
	if(left < MAX && right < MAX) {
		if(balls%2 == 0) return BS(right, balls/2);
		else return BS(left, balls/2 + 1);
	}
	else return node;
}

int main() {
	int t,d,x;
	cin >> t;
	while(t--) {
		cin >> d >> x;
		MAX = pow(2, d);
		cout << BS(1, x) << "\n";
	}

	return 0;
}