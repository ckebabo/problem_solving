#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n,m;
		cin >> n >> m;

		int v[100001] = {0,};
		map<int,int> mm;
		for(int i=0;i<n;i++) {
			scanf("%d", v+i);
			mm[v[i]] += 1;
		}

		int sum = 0;
		int cnt = 0;
		int ans[100001] = {0,};
		for(const auto &entry : mm) {
			const int k = entry.first - sum;
			if(k * (n-cnt) > m) {
				break;
			}
			m -= k*(n-cnt);
			sum += k;
			cnt += entry.second;
		}
		for(int i=0; i<n; i++) {
			ans[i] = min(sum, v[i]);
			v[i] = max(0, v[i]-sum);
		}

		const int p = m / (n-cnt);
		int r = m % (n-cnt);

		for(int i=0; i<n; i++) {
			if(v[i] > 0) { v[i]-=p; ans[i] += p; m -= p; }
		}
		for(int i=0; r>0; i++) {
			if(v[i] > 0) { v[i]-=1; ans[i] += 1; m -= 1; r -= 1; }
		}

		for(int i=0;i<n;i++) printf("%d ", ans[i]); puts("");
	}

	return 0;
}
