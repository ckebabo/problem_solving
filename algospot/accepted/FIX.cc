#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;

		int res = 0;
		for(int i=1;i<=N;i++) {
			int t;
			cin >> t;
			if(i==t) res++;
		}
		cout << res << endl;
	}

	return 0;
}
