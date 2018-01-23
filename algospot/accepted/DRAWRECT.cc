#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		vector<int> x(3);
		vector<int> y(3);

		for(int i=0;i<3;i++) scanf("%d %d", &x[i], &y[i]);
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());

		printf("%d %d\n",
				(x[1]==x[0] ? x[2] : x[0]),
				(y[1]==y[0] ? y[2] : y[0]));
	}

	return 0;
}
