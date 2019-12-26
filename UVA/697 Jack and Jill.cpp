#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PI 3.1415926535

int main() {
	int t=0, n;
	double UP,D,L,B,P,DOWN,V,X,R,A=32.2*12,ANS;
	while(cin >> UP && UP >= 1.0) {
		cin >> D >> L >> B >> P >> DOWN >> V;
		R = D/2;
		X = PI * R * R * L;
		ANS=0;
		n = ceil(V/B - 0.000000000001);
		if(t) printf("\n");
		printf("Scenario %d:\n", ++t);
		printf("     %-18s%8.2f sec\n", "up hill", UP);
		printf("     %-18s%8.2f in\n", "well diameter", D);
		printf("     %-18s%8.2f in\n", "water level", L);
		printf("     %-18s%8.2f cu ft\n", "bucket volume", B);
		printf("     %-18s%8.2f in/sec\n", "bucket ascent rate", P);
		printf("     %-18s%8.2f sec\n", "down hill", DOWN);
		printf("     %-18s%8.2f cu ft\n", "required volume", V);
		while(n--) {
			ANS += (UP + DOWN + (L/P) + sqrt(2*L/A));
			X += (B * 1728);
			L = (X/(PI*R*R));
		}
		printf("     %-18s%8.2f sec\n", "TIME REQUIRED", ANS);
	}

	return 0;
}
