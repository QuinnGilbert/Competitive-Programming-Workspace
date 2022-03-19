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

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> edge(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        edge[a].push_back(b,1);
        edge[b].push_back(a,-1);
    }

    int maxGCD=-1;

    for(int start=0;start<n;start++){
        
    }

}