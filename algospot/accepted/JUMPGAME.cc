#include <iostream>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		int n;
		cin >> n;

		int t[100][100];
		int r[100][100] = {{0,},};

		for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> t[i][j];

		r[0][0] = 1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(r[i][j]) {
					if(i+t[i][j] < n) r[i+t[i][j]][j] = 1;
					if(j+t[i][j] < n) r[i][j+t[i][j]] = 1;
				}
			}
		}

		cout << (r[n-1][n-1] ? "YES" : "NO") << endl;
	}

	return 0;
}
