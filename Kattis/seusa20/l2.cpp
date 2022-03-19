#include <bits/stdc++.h>

using namespace std;

long long MOD = 998244353;

long long count(int d, int n){

    vector<vector<long long>> dp(n,vector<long long>(10));
    for(int i=1;i<d;i++){
        dp[0][i]++;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<10;j++){
            long long count=0;
            if(j!=0) count++; //set to 1 to account for all initial 0 case
            for(int k=0;k<10;k++){
                if(j!=k)count = (count+dp[i-1][k])%MOD;
            }
            dp[i][j] = count;
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    long long result=0;
    for(int i=0;i<10;i++){
        result=(result+dp[n-1][i])%MOD;
    }
    if(n<3)result++;
    return result;

}

int main(){

    string s;
    cin>>s;
    long long result = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0')break;
        if(i==0||s[i]!=s[i-1]){
            result=(result+count(s[i]-'0',s.length()-i))%MOD;
        }else{
            result=(result+count(s[i]-'0'-1,s.length()-i))%MOD;
            break;
        }
        cout<<result<<endl;
    }

}

//44183-8302+1

/*
Forget about lower bound, just subtract it afterwards
actually maybe we can just go by digit
12345 = count(10000)+count(2000)+count(300)+count(20)+count(1) THIS DOES NOT WORK
you still need to avoid counting those duplicates

dp[i][j][k][m] = number of ways to end in digit j(0-9) at position i(0-n) with leading zeros if k(0-1) and at the upper bound if m(0-1)

654321

if leading zeros always add



*/