#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		int N;
		cin >> N; getc(stdin);

		string s;
		for(int i=0;i<N;i++) { string t; getline(cin, t); s+= '\n'+t; }
		s = s.substr(1);

		for(int i=0; i<s.size(); i++) {
			if(i+3<s.size() && isalpha(s[i]) && s[i+1]=='-' && s[i+2]=='\n' && isalpha(s[i+3])) {
				s.erase(i+1, 1);
				s.erase(i+1, 1);
			}
		}
		replace(s.begin(), s.end(), '-', ' ');
		replace(s.begin(), s.end(), '\n', ' ');

		int sum = 0, cnt=0;
		stringstream ss(s);
		string t;
		while(getline(ss, t, ' ')) {
			if(t.empty()) continue;
			sum += t.size();
			cnt += 1;
		}

		printf("%.3f\n", (float)sum/cnt);
	}

	return 0;
}
