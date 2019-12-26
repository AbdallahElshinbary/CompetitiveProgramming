#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> factors;

void factorize(int n) {
	int i;
	for(i=1; i*i<n; i++)
		if(n%i == 0) factors.push_back(i), factors.push_back(n/i);
	if(i*i == n) factors.push_back(i);
}

int main() {
	int n, c, size;
	while(cin >> n && n) {
		factors.clear();
		factorize(n);
		size = (int)factors.size(), c=0;
		for(int i=0; i<size; i++)
			for(int j=i+1; j<size; j++)
				if(factors[i]/__gcd(factors[i], factors[j])*factors[j] == n) c++;
		printf("%d %d\n", n, c+1);
	}

	return 0;
}
