#include <iostream>

using namespace std;

int main() {
	const int mod = 1000000007;
	int dp[101] = {0,1,2};

	for(int i=3;i<=100;i++) {
		dp[i] = (dp[i-1] + dp[i-2]) % mod;
	}

	int C;
	cin >> C;
	while(C--) {
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}

	return 0;
}
