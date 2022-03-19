#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    long long sum=0;
    cin>>n>>k;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int min = sum;
    sort(a.begin(),a.end(),greater<int>());
    vector<bool> dp(k+1);
    dp[0] = true;
    vector<bool> prev(k+1);
    prev[0] = true;
    for(int i=0;i<n;i++){
        sum-=a[i];
        for(int j=0;j<=k;j++){
            if(dp[j]&&sum+j>k-a[i]&&sum+j<min){
                min = sum+j;
            }
            if(j>=a[i]&&prev[j-a[i]]) dp[j] = true;
            //uses all values less than a[i], may use all values greater than a[i]
            //sum+j+a[i]>k since a[i] has not been used
        }
        prev = dp;
    }


    cout<<min<<"\n";

}


/*
We can either take or not take each value
the smallest values are the easiest to take
we must either use minx, or have a value larger than c-minx
6 12
1 2 3 4 5 6 
1+2+3+4 = 10 works
1+2+6 = 9 doesn't work

0 need >=12 can take any, must make 12 (1,2,3,4,5,6)
1 need >=11 can take any but 1, must make 10 (2,3,4,5,6)
1+2 need >=10 can take any but 1 and 2, must make 7 (3,4,5,6)
1+2+3 need >=9 can take any but 1,2,3 must make 3 (4,5,6)
1+2+3+4 need >=8 (5,6) + sum >12-5
1+2+3+4+5+6 always works ()



*/