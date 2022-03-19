#include <bits/stdc++.h>

using namespace std;

int choose(int n,int k){
    int n=0;
}

int main(){

}



/*

dp[0][0]=1 
dp[1][0]=0 1
dp[1][1]=0 
dp[2][0]=1 21
dp[2][1]=1 12
dp[3][0]=1 321
dp[3][1]=dp[2][0]*(2-1+1,1)+dp[2][1]*(2-1+0,0)
dp[3][2]=

sum[ dp[v-1][k-x]*choose(sum[v-1]-1+x,x) ]k->(0,count(v))



*/