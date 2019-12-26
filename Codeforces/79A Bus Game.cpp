#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int x,y,m;
	bool flag=true;
	cin >> x >> y;
	while(true) {
		if(flag) {
			if(x >= 2 && y >= 2) x-=2, y-=2;
			else if(x >= 1 && y >= 12) x--, y-=12;
			else if(y >= 22) y-=22;
			else break;
		} else {
			if(y >= 22) y-=22;
			else if(x >= 1 && y >= 12) x--, y-=12;
			else if(x >= 2 && y >= 2) x-=2, y-=2;
			else break;
		}
		flag = !flag;
	}
	cout << (!flag ? "Ciel" : "Hanako");

	return 0;
}
