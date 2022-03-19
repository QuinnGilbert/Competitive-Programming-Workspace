#include <bits/stdc++.h>

using namespace std;

long long MOD = 998244353;

long long solve(string s){
    int n = s.length();
    vector<vector<long long>> dp(n,vector<long long>(10));
    //initialize first row (might be able to make this more elegant)
    for(int i=0;i<=s[0]-'0';i++){
        dp[0][i]++;
    }
    for(int i=1;i<n;i++){
        //digits before end
        for(int j=0;j<=s[i]-'0';j++){
            long long count=0;
            for(int k=1;k<=9;k++){
                if(j!=k||k==0)count=(count+dp[i-1][k])%MOD;
            }
            dp[i][j] = count;
        }
        //digits after end
        for(int j=s[i]-'0'+1;j<=9;j++){
            long long count=0;
            for(int k=0;k<=9;k++){
                if(j!=k||k==0)count=(count+dp[i-1][k])%MOD;
            }
            dp[i][j] = count;
        }


        for(int j=0;j<10;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
        
    }
    long long result = 0;
    for(int i=0;i<10;i++){
        result = (result+dp[n-1][i])%MOD;
    }
    return result;
    
}

bool check(string s){
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]) return false;
    }
    return true;
}

int main(){

    string start,end;
    cin>>start>>end;

    int brute = 0;
    for(int i=1;i<stoi(end);i++){
        brute+=check(to_string(i));
    }
    cout<<"actual:"<<brute<<endl;

    while(start.length()<end.length()){
        start = '0'+start;
    }
    // long long result = (solve(end)-solve(start)+check(start)+MOD)%MOD;
    // cout<<solve(end)<<" "<<solve(start)<<" "<<check(start)<<endl;
    int x = solve(end);
    int y = solve(start);
    int z = check(start);
    cout<<x<<" "<<y<<" "<<z<<endl;
    // cout<<result<<endl;
}

//Forget about lower bound, just subtract it afterwards