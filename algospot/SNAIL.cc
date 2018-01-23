#include <iostream>
#include <numeric>

using namespace std;

int main() {
	int C;
	cin >> C;

	float t[1002][2002] = {{0,}};
	t[0][0] = 1;
	t[1][1] = 0.25; t[1][2] = 0.75;

	for(int i=1;i<=1000;i++) {
		t[i][i] = t[i-1][i-1]*0.25;
		for(int j=i+1;j<=2001;j++) {
			t[i][j] = t[i-1][j-2]*0.75 + t[i-1][j-1]*0.25;
		}
	}

	while(C--) {
		int n,m;
		cin >> n >> m;

		printf("%.10f\n", accumulate(t[m]+n, t[m]+2002, 0.));
	}

	return 0;
}
