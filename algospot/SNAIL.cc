#include <iostream>

using namespace std;

int main() {
	int C;
	cin >> C;

	float t[1002][1002] = {{0,}};
	for(int i=0;i<1002;i++) t[i][0] = 1;
	t[1][1] = 0.25; t[1][2] = 0.75;

	for(int i=1;i<=1000;i++) {
		for(int j=i;j<=1001;j++) {
			t[i][j] = t[i-1][j-2]*0.75 + t[i-1][j-1]*0.25;
		}
	}

	while(C--) {
		int n,m;
		cin >> n >> m;

		printf("%.10f\n", t[m][n] + t[m][n+1]);
	}

	return 0;
}
