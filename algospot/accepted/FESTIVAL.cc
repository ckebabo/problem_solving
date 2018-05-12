#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		int N,L;
		cin >> N >> L;

		int s[1002] = {0,};
		for(int i=1;i<=N;i++) {
			int t;
			cin >> t;
			s[i] = s[i-1] + t;
		}

		double ans = 100;
		for(int i=1;i<=N;i++) {
			for(int j=i+L-1;j<=N;j++) {
				ans = min(ans, (s[j] - s[i-1])/(j-i+1.));
			}
		}

		printf("%.10f\n", ans);
	}

	return 0;
}
