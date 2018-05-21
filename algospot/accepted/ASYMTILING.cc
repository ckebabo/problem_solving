#include <iostream>

using namespace std;

int main() {
	int s[105] = {0, 1, 2};
	int t[105] = {0, 1, 2, 1};

	const int mod = 1000000007;
	for(int i=3;i<=100;i++) {
		s[i] = (s[i-1] + s[i-2]) % mod;
		t[i] = (s[i/2] + s[(i-1)/2]) % mod;
	}

	int C;
	cin >> C;
	while(C--) {
		int n;
		cin >> n;
		cout << (mod+s[n] - t[n])%mod << endl;
	}

	return 0;
}
