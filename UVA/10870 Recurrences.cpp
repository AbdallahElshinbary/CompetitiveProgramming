#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX_N 15
struct Matrix {ll mat[MAX_N][MAX_N]{};};
ll d,n,MOD;

Matrix matMul(Matrix a, Matrix b) {
	Matrix ans; int i,j,k;
	for(i=0; i<MAX_N; i++)
		for(j=0; j<MAX_N; j++)
			for(ans.mat[i][j]=0, k=0; k<MAX_N; k++)
				ans.mat[i][j] += (a.mat[i][k]*b.mat[k][j])%MOD;
	return ans;
}

Matrix matPow(Matrix base, ll p) {
	Matrix ans; int i,j;
	for(i=0; i<MAX_N; i++)
		for(j=0; j<MAX_N; j++)
			ans.mat[i][j] = (i == j);	//identity matrix

	while(p) {
		if(p&1) ans = matMul(ans, base);
		base = matMul(base, base);
		p >>= 1;
	}

	return ans;
}

int main() {
	int a1[15], a2[15];

	while(cin >> d >> n >> MOD && n) {
		for(int i=0; i<d; i++) cin >> a1[i];
		for(int i=0; i<d; i++) cin >> a2[i];

		if(n <= d) {cout << a2[d-1] << "\n"; continue;}

		Matrix fibMat;
		for(int i=0; i<d; i++) {
			for(int j=0; j<d; j++) {
				if(i == 0) fibMat.mat[i][j] = a1[j];
				else fibMat.mat[i][j] = (i-1 == j);
			}
		}


		fibMat = matPow(fibMat, n-d);

		ll res = 0;
		for(int i=0; i<d; i++)
			res += (fibMat.mat[0][i]*a2[d-i-1])%MOD;
		cout << res%MOD << "\n";
	}

	return 0;
}