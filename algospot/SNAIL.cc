#include <iostream>

using namespace std;

int main() {
	int C;
	cin >> C;

	float t[1002][1002];
	t[0][0] = 1;
	for(int i=1;i<1002;i++) t[0][i] = 0;

	for(int i=1;i<=1000;i++) {
		t[i][0] = t[i][1] = 1;
		for(int j=2;j<=1001;j++) {
			if(i >= j) {
				t[i][j] = 1;
			} else {
				t[i][j] = t[i-1][j-2]*0.75 + t[i-1][j-1]*0.25;
			}
		}
	}

	while(C--) {
		int n,m;
		cin >> n >> m;

		float ans = 1.;
		if(m < n) {
			ans = t[m][n];
		}
		printf("%.10f\n", ans);
	}

	return 0;
}
