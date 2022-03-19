#include <bits/stdc++.h>
using namespace std;
	#define all(x) begin(x),end(x)
	using ll = long long;
	using vi = vector<int>;
	
	void solve() {
		int n, m;
		cin >> n >> m;
	
	vector<vi> msum(n + 1, vi(m));
		vector<vector<ll>> add(n + 1, vector<ll>(m + 1));

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
	
			for (int j = 0; j < m; j++) {
				int x = s[j] - '0';
				msum[i + 1][j] = msum[i][j] + (1 - x);
			}
		}

		// for(int i=0;i<=n;i++){
		// 	for(int j=0;j<m;j++){
		// 		cout << msum[i][j];
		// 	}
		// 	cout<<endl;
		// }
	
		ll overall = 0;
	
		for (int width = 1; width <= n; width++) {
	
			for (int i = 0; i + width <= n; i++) {
				// int ptr = 0;
	
				// for (int j = 0; j < m; j++) {
				// 	if (ptr < j) ptr = j;
					// while (ptr + 1 < m && msum[i + width][ptr + 1] - msum[i][ptr + 1] == 0)
					// 	ptr++;
	
				// 	if (msum[i + width][j] - msum[i][j] != 0)
				// 		continue;
	
					
				// }
	
				int l = 0;
	
				while (l < m) {
					int r = l;
					while (r + 1 < m && msum[i + width][r + 1] - msum[i][r + 1] == 0)
						r++;
	
					if (msum[i + width][l] - msum[i][l] != 0) {
						l++;
						continue;
					}
	
					overall += (ll(r - l + 1) * ll(r - l)) / 2;
					overall += r - l + 1;
	
					for (int j = l; j <= r; j++) {
						ll num = ll(j - l + 1) * ll(r - j + 1);
	
						add[i][j] += num;
						add[i + width][j] -= num;
					}
	
					l = r + 1;
				}
			}
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout << add[i][j] << " ";
			}
			cout << endl;
		}
	
		ll best = 0;
		int bx = -1, by = -1;
	
		for (int j = 0; j < m; j++) {
	
			ll here = 0;
	
			for (int i = 0; i < n; i++) {
				here += add[i][j];
	
				if (here > best) {
					best = here;
					bx = i;
					by = j;
				}
			}
		}
		
		cout << overall - best << "\n";
	}
	
	int main() {
		cin.tie(0)->sync_with_stdio(0);
		cin.exceptions(cin.failbit);
	
		solve();

		return 0;
	}
