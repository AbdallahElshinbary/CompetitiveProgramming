#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	double NCOWS, NCARS, NSHOW;
	while(scanf("%lf %lf %lf", &NCOWS, &NCARS, &NSHOW) != EOF)
		printf("%.5lf\n", ((NCOWS/(NCOWS+NCARS)) * (NCARS/(NCOWS+NCARS-NSHOW-1))) + ((NCARS/(NCOWS+NCARS)) * ((NCARS-1)/(NCOWS+NCARS-NSHOW-1))));

	return 0;
}
