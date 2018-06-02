#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;

		bitset<7> b(s);
		int aa = b.test(0) ^ b.test(2) ^ b.test(4) ^ b.test(6);
		int bb = b.test(0) ^ b.test(1) ^ b.test(4) ^ b.test(5);
		int cc = b.test(0) ^ b.test(1) ^ b.test(2) ^ b.test(3);

		int dd = aa + bb*2 + cc*4;
		if(dd) b.flip(7-dd);

		cout << b.test(4) << b.test(2) << b.test(1) << b.test(0) << endl;
	}

	return 0;
}
