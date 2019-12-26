#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int h1,h2,m1,m2;
	char c;
	cin >> h1 >> c >> m1;
	cin >> h2 >> c >> m2;

	int d;
	if(m2 < m1) {
		d = (60-m1)+m2 + ((h2-h1-1)*60);
	} else {
		d = (m2-m1) + ((h2-h1)*60);
	}
	d /= 2;
	int x = d/60;
	h1 += x;
	m1 += d%60;
	if(m1 >= 60) h1++, m1 %= 60;
	printf("%02d:%02d", h1, m1);

	return 0;
}
