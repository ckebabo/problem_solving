#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int C;
	cin >> C;

	while(C--) {
		int n;
		cin >> n;

		int t[105][105];
		int k;
		scanf("%d", &t[0][0]);
		for(int i=1;i<n;i++) {
			scanf("%d", &k);
			t[i][0] = t[i-1][0] + k;

			for(int j=1;j<i;j++) {
				scanf("%d", &k);
				t[i][j] = max(t[i-1][j-1], t[i-1][j]) + k;
			}

			scanf("%d", &k);
			t[i][i] = t[i-1][i-1] + k;
		}

		cout << *max_element(t[n-1], t[n-1]+n) << endl;
	}

	return 0;
}
