#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX_N 2
struct Matrix {ll mat[MAX_N][MAX_N]{};};

Matrix matMul(Matrix a, Matrix b) {
	Matrix ans; int i,j,k;
	for(i=0; i<MAX_N; i++)
		for(j=0; j<MAX_N; j++)
			for(ans.mat[i][j]=0, k=0; k<MAX_N; k++)
				ans.mat[i][j] += (a.mat[i][k]*b.mat[k][j]);
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
	//a^n + b^n = (a + b) × (a^n−1 + b^n−1) − (a × b) × (a^n−2 + b^n−2)

	ll p,q,n;
	while(cin >> p >> q >> n) {
		Matrix mat;
		mat.mat[0][0] = p; mat.mat[0][1] = -q;
		mat.mat[1][0] = 1; mat.mat[1][1] = 0;
		mat = matPow(mat,n);

		cout << (p*mat.mat[1][0] + 2*mat.mat[1][1]) << "\n";
	}

	return 0;
}
