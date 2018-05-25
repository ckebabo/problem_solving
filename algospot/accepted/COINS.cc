#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int M,C;
		cin >> M >> C;

		vector<int> coin(C);
		for(auto &k : coin) cin >> k;

		const int mod = 1000000007;
		int n[5001] = {0,};
		n[0] = 1;
		for(const auto &k : coin) {
			for(int i=0;i<=M;i++) {
				if(n[i]==0) continue;

				if(i+k <= M) n[i+k] = (n[i+k] + n[i]) % mod;
			}
		}

		cout << n[M] << endl;
	}

	return 0;
}
