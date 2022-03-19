#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> ivals(N);
	for (auto &ival : ivals)
		cin >> ival.first >> ival.second;
	vector<int64_t> win_counts(2 * M + 1);
	for (auto [a_i, b_i] : ivals)
		for (auto [a_j, b_j] : ivals)
			for (int k = a_i + a_j; k <= b_i + b_j; ++k)
				++win_counts.at(k);
	for (auto win : win_counts)
		cout << win << "\n";
}