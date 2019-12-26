#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int arr[100005]{};

	vector<int> squares;
	for(int i=1; i<=1000; i++) squares.push_back(i*i);

	int cnt = 0, idx = 0;
	for(int i=1; i<100005; i++) {
		if(i == squares[idx]) cnt++, idx++;
		arr[i] = cnt;
	}

	int a,b;
	while(cin >> a >> b && a)
		cout << arr[b]-arr[a-1] << "\n";


	return 0;
}
