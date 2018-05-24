#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		long long N,M,r0,c0,r,c,A,B;
		cin >> N >> M >> r0 >> c0 >> r >> c >> A >> B;
		cout << (abs(r-r0)+(A-1))/A + (abs(c-c0)+(B-1))/B << endl;
	}

	return 0;
}
