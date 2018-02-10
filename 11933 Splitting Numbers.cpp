#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(cin >> n && n != 0) {
		bitset<32> bs(n);
		vector<int> v;
		for(int i=0; i<32; i++) {
			if(bs.test(i))
				v.push_back(i);
		}

		int a=0, b=0;
		for(int i=0; i<v.size(); i+=2)
			a += pow(2, v[i]);
		for(int i=1; i<v.size(); i+=2)
			b += pow(2, v[i]);

		cout << a << " " << b << "\n";
	}

	return 0;
}

