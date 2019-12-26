#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX_N 3
struct Matrix {ll mat[MAX_N][MAX_N];};
ll n,MOD=1000000009;

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
	int arr[3] = {2,1,0};
	while(cin >> n && n) {
		if(n <= 3) {cout << (n-1)%MOD << "\n"; continue;}

		Matrix fibMat;
		fibMat.mat[0][0] = 1; fibMat.mat[0][1] = 1; fibMat.mat[0][2] = 1;
		fibMat.mat[1][0] = 1; fibMat.mat[1][1] = 0; fibMat.mat[1][2] = 0;
		fibMat.mat[2][0] = 0; fibMat.mat[2][1] = 1; fibMat.mat[2][2] = 0;
		fibMat = matPow(fibMat, n-3);

		ll res = 0;
		for(int i=0; i<3; i++)
			res += (fibMat.mat[0][i]*arr[i])%MOD;
		cout << res%MOD << "\n";
	}

	return 0;
}