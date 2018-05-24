#include <iostream>
#include <queue>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N,M;
		cin >> N >> M;

		priority_queue<int> q;
		for(int i=0;i<N;i++) {
			int k;
			cin >> k;
			q.push(k);
		}

		int ans=0;
		while(!q.empty() && M--) {
			int k = q.top(); q.pop();
			ans += k;
			if(k>1) q.push(k-1);
		}
		cout << ans << endl;
	}

	return 0;
}

