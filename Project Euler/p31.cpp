#include <bits/stdc++.h>

using namespace std;

int main(){

    int a[] = {1,2,5,10,20,50,100,200};
    vector<int> dp(201);
    dp[0] = 1;
    for(int i=0;i<8;i++){
        for(int j=a[i];j<=200;j++){
            dp[j]+=dp[j-a[i]];
        }
    }
    cout<<dp[200]<<endl;
}