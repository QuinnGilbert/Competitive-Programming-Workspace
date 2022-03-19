#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n >> n;
	vector<pair<int,int>> jobs(n);
	for (auto &[a,b]: jobs) cin >> a >> b;
	
	long res = LONG_MAX;
	for (int dir = 0; dir <= 1; dir++) {
		int xmin = INT_MAX, xmax = INT_MIN;

		vector<pair<int,int>> events;
		for (auto [a,b]: jobs) {
			xmin = min(xmin, min(a, b));
			xmax = max(xmax, max(a, b));
			
			if (a > b) {
				events.emplace_back(a, 1);
				events.emplace_back(b, -1);
			}
		}
		sort(begin(events), end(events));
		
		int balance = 0, start = 0;
		vector<pair<int,int>> back_intervals;
		back_intervals.emplace_back(xmin, xmin);
		for (auto [x,add]: events) {
			if (balance == 0) start = x;
			balance += add;
			if (balance == 0) back_intervals.emplace_back(start, x);
		}
		back_intervals.emplace_back(xmax, xmax);

		long best = xmin;
		for (auto [a,b]: back_intervals) {
			res = min(res, 2*(xmax-xmin) + best - a);
			best = min(long(b), best + 2*(b-a));
		}

		for (auto &[a,b]: jobs) a = -a, b = -b;
	}
	cout << res << endl;
}

//g++ -std=gnu++17 paul.cpp