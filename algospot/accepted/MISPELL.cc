#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	for(int i=1;i<=N;i++) {
		int M;
		string s;
		cin >> M >> s;
		s.erase(M-1, 1);
		cout << i << " " << s << endl;
	}

	return 0;
}
