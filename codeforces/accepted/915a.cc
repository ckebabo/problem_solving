#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n,k;
	cin >> n >> k;

	int v = 0;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		if(k % t == 0) v = max(v, t);
	}

	cout << k/v << endl;

	return 0;
}
