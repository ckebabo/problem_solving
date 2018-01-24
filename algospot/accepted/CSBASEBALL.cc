#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int a,b;
		cin >> a >> b;

		cout << (a>b ? 0 : 3+b-a+1) << endl;
	}

	return 0;
}

