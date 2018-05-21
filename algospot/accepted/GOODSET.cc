#include <iostream>
#include <numeric>
#include <cstdio>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		int N,M;
		cin >> N >> M;

		bool ans = true;
		int p[501] = {0,};
		for(int i=0;i<N;i++) {
			int n;
			cin >> n;
			if(n==M || n==0) ans=false;

			for(int j=0;j<n;j++) {
				int k;
				cin >> k;
				p[k] = 1;
			}
		}

		if(accumulate(p+1, p+M+1, 0)!=M) {
			ans = false;
		}
		puts(ans ? "YES" : "NO");
	}

	return 0;
}
