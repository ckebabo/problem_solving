#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int k[1000001] = {0,};

int main() {
	string s;
	cin >> s;

	k[0] = (s[0]=='1' ? 1 : 0);
	for(int i=1;i<s.size();i++) {
		k[i] = k[i-1];

		if(s[i]=='1') {
			k[i] += 1;
		}
	}

	int N;
	cin >> N;
	while(N--) {
		int i,j;
		cin >> i >> j;
		if(i>j) swap(i,j);

		if((k[i]==k[j] && s[i]!='1') || (s[i]=='1' && k[j]-k[i]==j-i)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}
