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

    int tests;cin>>tests;
    while(tests--){

        int n,m;cin>>n>>m;
        vector<int> a(n);
        vector<vector<tuple<int,long long,long long>>> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            int e,t,p;cin>>e>>t>>p;
            b[e-1].emplace_back(p,t,i);
        }
        int curTime=0;
        bool works=true;
        vector<int> result;
        for(int i=0;i<n;i++){
            // cout<<"i: "<<i<<endl;
            vector<vector<long long>> dp(b[i].size()+1,vector<long long>(101,LONG_LONG_MAX/2));
            dp[0][0] = 0;
            int index=0;
            // cout<<"CHECK1"<<endl;
            for(auto [first,second,third]:b[i]){
                index++;
                dp[index] = dp[index-1];
                for(int j=0;j<=100;j++){
                    dp[index][j] = min(dp[index][j], dp[index-1][max(0,j-first)]+second);
                }
            }
            // cout<<"CHECK2"<<endl;
            if(dp[index][100]+curTime>a[i]){
                works=false;
                break;
            }
            curTime+=dp[index][100];

            //backtrack to get needed values
            int percent=100;
            for(int j=index;j>0;j--){
                // cout<<j-1<<" "<<b.size()<<endl;
                if(percent>=0 && dp[j][percent]!=dp[j-1][percent]){
                    // cout<<percent<<" "<<dp[j][percent]<<" "<<dp[j-1][percent]<<" "<<get<2>(b[i][j])<<" "<<get<0>(b[i-1][j])<<endl;;
                    result.push_back(get<2>(b[i][j-1]));
                    percent-=get<0>(b[i][j-1]);
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