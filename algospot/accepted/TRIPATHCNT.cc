#include <iostream>
#include <utility>

using namespace std;

int main() {
	int C;
	cin >> C;

	while(C--) {
		int n;
		cin >> n;

		int T[101][101] = {{0,},};
		for(int i=0;i<n;i++) {
			for(int j=0;j<=i;j++) {
				cin >> T[i][j];
			}
		}

		pair<int,int> dp[101][101];
		dp[0][0] = make_pair(T[0][0], 1);
		for(int i=1;i<n;i++) {
			dp[i][0] = make_pair(dp[i-1][0].first+T[i][0], dp[i-1][0].second);
			for(int j=1;j<i;j++) {
				if(dp[i-1][j-1].first > dp[i-1][j].first) {
					dp[i][j] = make_pair(dp[i-1][j-1].first + T[i][j], dp[i-1][j-1].second);
				} else if(dp[i-1][j-1].first < dp[i-1][j].first) {
					dp[i][j] = make_pair(dp[i-1][j].first + T[i][j], dp[i-1][j].second);
				} else {
					dp[i][j] = make_pair(dp[i-1][j].first + T[i][j], dp[i-1][j].second + dp[i-1][j-1].second);
				}
			}
			dp[i][i] = make_pair(dp[i-1][i-1].first+T[i][i], dp[i-1][i-1].second);
		}

		int m=0, cm=0;
		for(int i=0;i<n;i++) {
			if(dp[n-1][i].first > m) {
				m = dp[n-1][i].first;
				cm=dp[n-1][i].second;
			} else if(dp[n-1][i].first == m) {
				cm += dp[n-1][i].second;
			}
		}

		cout << cm << endl;
	}

	return 0;
}
