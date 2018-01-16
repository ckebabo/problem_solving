#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <deque>
#include <cmath>

using namespace std;

float dist(pair<float, float> &a, pair<float, float> &b) {
	return (a.first-b.first)*(a.first-b.first) + 
		(a.second-b.second)*(a.second-b.second);
}

bool isok(vector<pair<float, float>> &pts, float d) {
	int v[100] = {0,};
	v[0] = 1;

	deque<int> q;
	q.push_back(0);
	while(!q.empty()) {
		int t = q.front(); q.pop_front();

		for(int i=0;i<pts.size();i++) {
			if(v[i] == 0 && dist(pts[t], pts[i])<=d*d) {
				v[i] = 1;
				q.push_back(i);
			}
		}
	}

	int cnt=0;
	for(int i=0;i<pts.size();i++) cnt+=v[i];

	return cnt == pts.size();
}

float solve(vector<pair<float, float>> &pts) {
	float low = 0, high = 1001;
	float cand;

	for(;;) {
		cand = (low+high)/2;

		if(isok(pts, cand)) {
			high = cand;
		} else {
			low = cand;
		}

		if(fabs(cand - (low+high)/2) < 1e-8) {
			break;
		}
	}

	return cand;
}

int main() {
	int C;
	cin >> C;

	while(C--) {
		int N;
		cin >> N;

		vector<pair<float, float>> pts(N);
		for(auto &pt : pts) {
			cin >> pt.first >> pt.second;
		}

		printf("%.2f\n", solve(pts));
	}

	return 0;
}
