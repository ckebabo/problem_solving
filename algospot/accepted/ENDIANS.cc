#include <iostream>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		unsigned int n;
		cin >> n;
		n = (n>>24) | ((n>>8) & (0XFF<<8)) | ((n<<8) & (0XFF<<16)) | (n<<24);
		cout << n << endl;
	}

	return 0;
}
