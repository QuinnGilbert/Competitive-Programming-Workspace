#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    for(int t=0;t<n;t++){
        string a,b;
        cin>>a>>b;
        vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1));
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                if(a[i]==a[j]){
                    dp[i+1][j+1]+=dp[i][j];
                }
            }
        }
    }


}