#include <iostream>
#include <vector>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		int N;
		cin >> N;

		int t[200][200];
		int r[200][200];

		for(int i=0;i<N;i++) for(int j=0;j<=i;j++) cin >> t[i][j];
		for(int i=N;i<N*2-1;i++) for(int j=0;j<N*2-i-1;j++) cin >> t[i][j];

		r[0][0] = t[0][0];
		for(int i=1;i<N;i++) {
			r[i][0] = r[i-1][0] + t[i][0];
			for(int j=1;j<i;j++) {
				r[i][j] = max(r[i-1][j], r[i-1][j-1]) + t[i][j];
			}
			r[i][i] = r[i-1][i] + t[i][i];
		}
		for(int i=N;i<N*2-1;i++) {
			for(int j=0;j<N*2-i-1;j++) {
				r[i][j] = max(r[i-1][j], r[i-1][j+1]) + t[i][j];
			}
		}

		cout << r[N*2-2][0] << endl;
	}

	return 0;
}
