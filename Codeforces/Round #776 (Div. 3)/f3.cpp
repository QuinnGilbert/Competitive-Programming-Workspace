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
        vector<ll> a(n);
        for(ll &i:a){
            cin>>i;
        }
        vector<vector<tuple<ll,ll,ll>>> b(n);
        for(int i=0;i<m;i++){
            ll e,t,p;cin>>e>>t>>p;
            e--;
            b[e].emplace_back(t,p,i);
        }

        
        vector<int> result;
        ll prevTime=0;
        bool works=true;
        for(int task=0;task<n;task++){

            vector<vector<ll>> dp(b[task].size()+1,vector<ll>(101,LONG_MAX/2));
            dp[0][0]=0;
            int i=0;
            for(auto [time,percent,index]:b[task]){
                i++;
                dp[i]=dp[i-1];
                for(int j=0;j<=100;j++){
                    ll prev=0;
                    if(j-percent>0){
                        prev = j-percent;
                    }
                    dp[i][j] = min(dp[i][j],dp[i-1][prev]+time);
                }
            }

            if(dp[b[task].size()][100]+prevTime>a[task]){
                works=false;
                break;
            }
            prevTime+=dp[b[task].size()][100];

            int percent=100;
            int index=b[task].size();
            while(percent>0){
                // cout<<time<<" "<<index<<" "<<task<<endl;
                if(dp[index][percent]==dp[index-1][percent]){
                    index--;
                }else{
                    result.push_back(get<2>(b[task][index-1]));
                    percent-=get<1>(b[task][index-1]);
                    index--;
                }
            }

        }

        if(works){
            cout<<result.size()<<endl;
            for(int i:result){
                cout<<i+1<<" ";
            }
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }

    }

}