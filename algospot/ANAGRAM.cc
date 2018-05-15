#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		string a,b;
		cin >> a >> b;
		sort(begin(a), end(a));
		sort(begin(b), end(b));

		cout << (a==b ? "Yes" : "No.") << endl;
	}

	return 0;
}
