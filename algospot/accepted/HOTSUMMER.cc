#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int k;
		vector<int> v(9);

		cin >> k;
		for(auto &a : v) cin >> a;
		cout << (std::accumulate(v.begin(), v.end(), 0) <= k ? "YES" : "NO") << endl;
	}

	return 0;
}
