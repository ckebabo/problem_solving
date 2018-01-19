#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N;
		cin >> N;

		vector<int> a(N);
		for(auto &v : a) cin >> v;

		int ans = 0;

		sort(a.begin(), a.end());
		for(int i=0;i<N/2;i++) {
			ans = max(a[i]+a[N-i-1], ans);
		}
		if(N%2 == 1) {
			ans = max(a[N/2]*2, ans);
		}

		printf("%.1f\n", ans/2.);
	}

	return 0;
}
