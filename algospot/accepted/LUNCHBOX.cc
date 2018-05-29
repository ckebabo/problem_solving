#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(const pair<int,int> &d1, const pair<int,int> &d2) {
	if(d1.second == d2.second) {
		return d1.first < d2.first;
	}

	return d1.second > d2.second;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		
		vector<pair<int,int>> v(N);
		for(auto &k : v) cin >> k.first;
		for(auto &k : v) cin >> k.second;

		sort(v.begin(), v.end(), comp);

		int now=0, ans=0;
		for(const auto &k : v) {
			now += k.first;
			ans = max(ans, now+k.second);
		}

		cout << ans << endl;
	}

	return 0;
}
