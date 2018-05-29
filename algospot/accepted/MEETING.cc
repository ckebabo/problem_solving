#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;

		vector<int> m(N),w(N);
		for(auto &k : m) cin >> k;
		for(auto &k : w) cin >> k;

		sort(m.begin(), m.end());
		sort(w.begin(), w.end());

		int ans = 0;
		for(int i=0;i<N;i++) {
			ans += abs(m[i]-w[i]);
		}

		cout << ans << endl;
	}

	return 0;
}
