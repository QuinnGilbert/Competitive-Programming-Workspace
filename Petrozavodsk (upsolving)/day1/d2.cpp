#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int get(int n, int b){
    if(b&1) return n&1;
    n %= (b+1);
    if(n == b) return 2;
    return n&1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    // int b = 4;
    // vector<int> num(100, 0);
    // for(int i = 1; i < num.size(); i++){
    //     int cp = 1;
    //     vector<int> seen(30, 0);
    //     while(cp <= i) seen[num[i-cp]] = 1, cp *= b;
    //     while(seen[num[i]]) num[i]++;
    // }
    // set<string> sets;
    // string cur = "";
    // for(int i = 0; i < num.size(); i++){
    //     cur += to_string(num[i]);
    //     if(cur.size() == b+1){
    //         sets.insert(cur);
    //         cur = "";
    //     }
    // }
    // for(auto x : num) cout << x;
    // cout << endl;
    // for(auto x : sets) cout << x << endl;

    int n; cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        nums.push_back(get(a, b));
    }
    // for(auto x : nums) cout << x << " ";
    // cout << endl;
    int xx = 0;
    for(auto x : nums) xx ^= x;
    // cout << xx << endl;

    
    if(xx&2) cout << "Alice\n"; // 2, 3
    else{
        if(xx) cout << "Alice\n"; // 1
        else cout << "Bob\n";
    }
    
    return 0;
}