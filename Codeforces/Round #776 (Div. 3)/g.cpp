#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int main(){

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;cin>>t;
    while(t--){
        
        int n,m;cin>>n>>m;
        int s,e;cin>>s>>e;
        vector<vector<int>> edge(n);
        for(int i=0;i<m;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        vector<int> dist(n);
        vector<long long> count(n);
        vector<int> v(n);

    }

}

/*
Key Observation: After moving to the non-ideal path a single time, you must only move the ideal path the rest of the way, so we can
*/