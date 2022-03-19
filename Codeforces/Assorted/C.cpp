#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;
    for(int test=0;test<t;test++){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int add=0;
        int index=0;
        while(index<n-1&&(a[index]+add<0||a[index+1]-(a[index]+add)+add>a[index]+add)){
            add-=(a[index]+add);
            // cout<<index<<add<<" ";
            index++;
        }
        // cout<<endl;
        cout<<a[index]+add<<endl;
    }

}