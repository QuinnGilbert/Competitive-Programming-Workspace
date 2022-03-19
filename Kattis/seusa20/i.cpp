#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<bool>> a(m,vector<bool>(m));
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i!=j) a[i][j] = true;
        }
    }
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            for(int k=j+1;k<m;k++){
                a[s[k]-'A'][s[j]-'A'] = false;
            }
        }
    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    vector<vector<bool>> dp(m,vector<bool>(m));
    int max=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==0){
                dp[i][j] = true;
                continue;
            }
            bool check = false;
            for(int k=0;k<m;k++){
                if(a[k][j]&&dp[i-1][k]){
                    check = true;
                }
            }
            dp[i][j] = check;
            if(dp[i][j]){
                max = i;
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    cout<<max+1<<endl;
    


}

/*

if a comes before b and b comes before 
store the maximum value that comes before each letter 

*/