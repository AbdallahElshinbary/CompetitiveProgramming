#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x;
	while(cin >> n && n != 0) {
		priority_queue<int, vector<int>, greater<int> > q;
		for(int i=0; i<n; i++) {
			cin >> x;
			q.push(x);
		}

		int a,b,cnt = 0;
		while(q.size() > 1) {
			a=q.top(); q.pop();
			b=q.top(); q.pop();
			cnt += a+b;
			q.push(a+b);
		}
		cout << cnt << endl;
	}
	return 0;
}
