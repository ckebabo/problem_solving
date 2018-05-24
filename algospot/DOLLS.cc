#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n,m;
		cin >> n >> m;

		vector<int> v(n);
		for(auto &a : v) cin >> a;

		vector<int> s(v);
		sort(begin(s), end(s));

		int sum = 0;
		int ans[100001] = {0,};
		while(m) {
			const int k = s.front() - sum;
			if(k * s.size() <= m) {
				m -= k * s.size();
				sum += k;
				s.erase(s.begin());

				for(int i=0; i<n; i++) {
					if(v[i] >= k) { v[i]-=k; ans[i] += k; }
				}
			} else {
				const int p = m / s.size();
				int r = m % s.size();

				for(int i=0; i<n; i++) {
					if(v[i] > 0) { v[i]-=p; ans[i] += p; m -= p; }
				}
				for(int i=0; r>0; i++) {
					if(v[i] > 0) { v[i]-=1; ans[i] += 1; m -= 1; r -= 1; }
				}
			}
		}

		for(int i=0;i<n;i++) printf("%d ", ans[i]); puts("");
	}

	return 0;
}
