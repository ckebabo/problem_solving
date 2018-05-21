#include <iostream>
#include <cstdio>

using namespace std;

const int mod = 10007;

void multiply(int mat1[][100], int mat2[][100], int n) {
	int res[100][100] = {{0,},};

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			for(int k=0;k<n;k++) {
				res[i][j] = (res[i][j] + mat1[i][k] * mat2[k][j]) % mod;
			}
		}
	}
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) mat1[i][j] = res[i][j];
}

void power(int mat[][100], int n, int p) {
	if(p==1) return;
	if(p==2) {
		multiply(mat, mat, n);
		return;
	}

	if(p%2==0) {
		power(mat, n, p/2);
		power(mat, n, 2);
	} else {
		int orig[100][100];
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) orig[i][j] = mat[i][j];

		power(mat, n, p/2);
		power(mat, n, 2);
		multiply(mat, orig, n);
	}
}

int main() {
	int C;
	cin >> C;
	while(C--) {
		int mat[100][100];
		int n, p;
		cin >> n >> p;

		for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d", &mat[i][j]);

		power(mat, n, p);

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				printf("%d ", mat[i][j]);
			}
			puts("");
		}
	}

	return 0;
}
