#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n = 7;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        if(a[0]+a[1]==a[2]){
            cout<<a[0]<<" "<<a[1]<<" "<<a[3]<<endl;
        }else{
            cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
        }
    }
}