#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int week[] = {2,1,1,2,3,1,3};
	int a=3, b=2, c=2;
	int x,y,z,w;
	cin >> x >> y >> z;
	w = min(x/a, min(y/b, z/c));
	x -= w*a, y -= w*b, z -= w*c;

	int add=0, temp, tx,ty,tz;
	for(int i=0; i<7; i++) {
		temp=0, tx=x, ty=y, tz=z;
		for(int j=i;; j=(j+1)%7) {
			if(week[j] == 1) {
				if(!tx) break;
				temp++, tx--;
			}
			else if(week[j] == 2) {
				if(!ty) break;
				temp++, ty--;
			}
			else if(week[j] == 3) {
				if(!tz) break;
				temp++, tz--;
			}
		}
		add = max(add, temp);
	}
	cout << w*7 + add;

	return 0;
}
