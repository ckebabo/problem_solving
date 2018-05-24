#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int c;
	cin >> c;
	while(c--) {
		int n;
		int r[200], p[200];
		cin >> n;
		for(int i=0;i<n;i++) cin >> r[i];
		for(int i=0;i<n;i++) cin >> p[i];

		int gcd = r[0];
		for(int i=1;i<n;i++) gcd = __gcd(gcd, r[i]);
		for(int i=0;i<n;i++) r[i] /= gcd;

		int k = 1;
		for(int i=0;i<n;i++) {
			k = max(k, (p[i]+r[i]-1)/r[i]);
		}

		int ans[200] = {0,};
		for(int i=0;i<n;i++) {
			ans[i] = r[i]*k - p[i];
			if(p[i]+ans[i] < r[i]*gcd) {
				ans[i] = r[i]*gcd - p[i];
			}
		}

		for(int i=0;i<n;i++) {
			printf("%d ", ans[i]);
		}
		puts("");
	}

	return 0;
}
