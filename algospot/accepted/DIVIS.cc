#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
	string s;
	while(cin >> s) {
		if(s=="end") break;
		reverse(s.begin(), s.end());

		int n=0;
		for(int i=0;i<s.size();i++) {
			int k = 0;
			if(isdigit(s[i])) k = s[i]-'0';
			else if(isupper(s[i])) k = s[i]-'A'+10;
			else if(islower(s[i])) k = s[i]-'a'+10+26;
			n = (n*62 + k) % 61;
		}

		cout << (n==0 ? "yes" : "no") << endl;
	}

	return 0;
}
