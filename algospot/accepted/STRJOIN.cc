#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int C;
	cin >> C;
	while(C--) {
		int N;
		cin >> N;

		priority_queue<int, vector<int>, greater<int> > q;
		for(int i=0;i<N;i++) {
			int n;
			cin >> n;
			q.push(n);
		}

		int ans = 0;
		while(q.size()!=1) {
			int n1 = q.top(); q.pop();
			int n2 = q.top(); q.pop();

			ans += n1+n2;
			q.push(n1+n2);
		}
		cout << ans << endl;
	}

	return 0;
}
