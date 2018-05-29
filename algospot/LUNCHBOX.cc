#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		
		vector<pair<int,int>> v(N);
		for(auto &k : v) cin >> k.first;
		for(auto &k : v) cin >> k.second;

		sort(v.begin(), v.end());

		int now=0, ans=0;
		for(const auto &k : v) {
			now += k.first;
			ans = max(ans, now+k.second);
		}

		cout << ans << endl;
	}

	return 0;
}
