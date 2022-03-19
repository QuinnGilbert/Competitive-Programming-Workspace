#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;cin>>n;
    int xg,yg;cin>>xg>>yg;

    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }


    vector<int> result(n+1);
    for(int j=0;j< 1<<n ;j++){
        for(int i=0;i<n;i++){
            if(j & (1<<i) > 0){
                
            }
        }
    }


    for(int i=1;i<=n;i++){
        cout<<result[i]<<endl;
    }

}