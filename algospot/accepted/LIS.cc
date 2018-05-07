#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(const vector<int> &l) {
	const size_t k = l.size();
	int res[505] = {0,};

	for(int i=0; i<k; i++) {
		res[i] = 1;
		for(int j=0; j<i; j++) {
			if(l[i] > l[j]) res[i] = max(res[i], res[j]+1);
		}
	}

	return *max_element(res, res+k);
}

int main() {
	int C;
	cin >> C;

	while(C--) {
		int N;
		cin >> N;

		vector<int> l(N);
		for(auto &n : l) {
			cin >> n;
		}

		cout << lis(l) << endl;
	}

	return 0;
}
