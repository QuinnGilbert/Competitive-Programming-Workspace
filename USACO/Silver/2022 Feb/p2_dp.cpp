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


    int n;cin>>n;
    int xg,yg;cin>>xg>>yg;
    vector<pair<long long,long long>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }

    map<long long,map<long long,map<int,long long>>> dp;
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        map<long long,map<long long,map<int,long long>>> next = dp;
        for(auto [x, ymap]:dp){
            for(auto [y, usedmap]:ymap){
                for(auto [numused, count]:usedmap){
                    next[x+a[i].first][y+a[i].second][numused+1]+=count;
                }
            }
        }
        dp=next;
    }
    for(int i=1;i<=n;i++){
        cout<<dp[xg][yg][i]<<"\n";
    }
}

/*

dp[curx][cury][numused] = numways

*/