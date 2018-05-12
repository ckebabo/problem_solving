#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		string s;
		cin >> s;

		stack<char> st;
		for(auto c : s) {
			if(string("({[").find(c) != string::npos) {
				st.push(c);
			} else {
				if(st.empty()) { st.push('a'); break; }
				char ch = st.top();
				if(!((ch=='(' && c==')') ||
					(ch=='{' && c=='}') ||
					(ch=='[' && c==']'))) {
					break;
				}
				st.pop();
			}
		}

		if(st.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
