#include <bits/stdc++.h>
#define int long long
using namespace std;
 
template<typename Is, typename T> Is & operator >> (Is & is, vector<T> & v) { for (auto & x : v) is >> x; return is; }
template<typename Is, typename U1, typename U2> Is & operator >> (Is & is, pair<U1, U2> & p) { return is >> p.first >> p.second; }
template<typename Os, typename T> Os & operator << (Os & os, const vector<T> & v) { for (const auto & x : v) os << x << ' '; return os; }
template<typename Os, typename U1, typename U2> Os & operator << (Os & os, const pair<U1, U2> & p) { return os << p.first << ' ' << p.second; }
 
#define debug(x) cerr << #x << ": " << x << endl;
 
void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	cin >> a >> b;
	int cost = min(abs(a[0] - b[0]) + abs(a.back() - b.back()), abs(a[0] - b.back()) + abs(b[0] - a.back()));
	{
		int ca = INT_MAX;
		for (int i = 0; i < n; i++)
			ca = min(ca, abs(a[i] - b[0]) + abs(a[i] - b.back()));
		int cb = INT_MAX;
		for (int i = 0; i < n; i++)
			cb = min(cb, abs(b[i] - a[0]) + abs(b[i] - a.back()));
		cost = min(cost, ca + cb);
	}
	{ // take 0 0
		int c = abs(a[0] - b[0]);
		int ca = INT_MAX;
		for (int i = 0; i < n; i++)
			ca = min(ca, abs(a[i] - b.back()));
		int cb = INT_MAX;
		for (int i = 0; i < n; i++)
			cb = min(cb, abs(b[i] - a.back()));
		cost = min(cost, c + ca + cb);
	}
	{ // take n - 1 n - 1
		int c = abs(a.back() - b.back());
		int ca = INT_MAX;
		for (int i = 0; i < n; i++)
			ca = min(ca, abs(a[i] - b[0]));
		int cb = INT_MAX;
		for (int i = 0; i < n; i++)
			cb = min(cb, abs(b[i] - a[0]));
		cost = min(cost, c + ca + cb);
	}
	cout << cost << '\n';
}
 
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t; while (t--) solve();
	return 0;
}
