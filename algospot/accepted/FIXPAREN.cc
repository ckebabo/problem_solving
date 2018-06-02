#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string s, open;
		cin >> s >> open;

		string close;
		for(auto ch : open) {
			if(ch=='{') close+='}';
			else if(ch=='(') close+=')';
			else if(ch=='<') close+='>';
			else if(ch=='[') close+=']';
		}

		stack<int> st;
		for(int pos=0;pos<s.size();pos++) {
			size_t k = open.find(s[pos]);
			if(k != string::npos) {
				st.push(pos);
			} else {
				const int ci = st.top();
				const size_t a = open.find(s[ci]);
				const size_t b = close.find(s[pos]);

				if(s[ci] != open[k]) {
					if(a<b) {
						s[pos] = close[a];
					} else {
						s[ci] = open[b];
					}
				}
				st.pop();
			}
		}

		cout << s << endl;
	}

	return 0;
}
