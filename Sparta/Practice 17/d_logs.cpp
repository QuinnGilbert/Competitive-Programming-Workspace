#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,d;
    cin>>n>>d;
    vector<int> a(n+1);
    vector<int> freq(1001);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        freq[a[i]]++;
    }

    vector<vector<long long>> dp(n+1,vector<long long>(10));
    vector<vector<vector<int>>> result(n+1,vector<vector<int>>(10));

    for(int i=1;i<=n;i++){
        for(int j=0;j<10;j++){
            dp[i][j]=dp[i-1][j];
        }
        for(int j=0;j<10;j++){
            if(dp[i-1][j]!=-1){
                double x = dp[i-1][j];
                // cout<<dp[i][(a[i]*j)%10]<<endl;
                if(dp[i][(a[i]*j)%10]==-1||x+log(a[i])>dp[i][(a[i]*j)%10]){
                    dp[i][(a[i]*j)%10]=x+log(a[i]);
                }
            }
            if(dp[i][a[i]%10]<log(a[i])){
                dp[i][a[i]%10] = log(a[i]);
            }
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<10;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    if(dp[n][d]==-1){
        cout<<-1<<endl; 
    }else{
        double prevmax=dp[n][d];
        vector<int> result;
        for(int i=n-1;i>=0;i--){
            int max=-1;
            for(int j=0;j<10;j++){
                if((dp[i][j]==-1&&abs(prevmax-log(a[i+1]))<.0001)||abs(prevmax-log(a[i+1])-dp[i][j])<.0001 ){
                    // max=dp[i][j];
                    result.push_back(a[i+1]);
                    prevmax=dp[i][j];
                    break;
                }
            }
            // if(max!=prevmax&&max!=-1){
            //     prevmax=max;
            // }
        }
        cout<<result.size()<<endl;
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }




}