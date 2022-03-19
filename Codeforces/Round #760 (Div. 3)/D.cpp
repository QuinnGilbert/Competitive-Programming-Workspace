#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        sort(a.begin(),a.end());
        for(int i=0;i<k;i++){
            // cout<<n-i-k<<" "<<n-i<<endl;
            sum+=a[n-i-k-1]/a[n-i-1];
            sum-=(a[n-i-k-1]+a[n-i-1]);
            // cout<<"CHECK"<<endl;
        }
        cout<<sum<<endl;
    }

}

/*

cannot greedily remove the values that decrease by the most (first input breaks this)

you would want to remove both 2 and 3 if you only had 1 move, but with 2 moves you should instead remove 

1 10 10 1 10 2 7 10 3
1 1 2 3 7 10 10 10 10

you should always remove the top value and the top value after k steps?


1 1 1 2 1 3 1
1 1 1 1 1 2 3




*/