#include <bits/stdc++.h>

using namespace std;

void go(vector<string> &a, int index, int k, vector<bool> &b){
    // cout << index << endl;
    if(index==a.size()){
        if(k==0){
            for(int i=0;i<a.size();i++){
                if(b[i]){
                    cout <<a[i]<<" ";
                }
            }
            cout << endl;
        }
        return;
    }
    b[index]=true;
    go(a,index+1,k-1,b);
    b[index]=false;
    go(a,index+1,k,b);
}

int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n,k;
        cin>>n>>k;
        vector<string> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        vector<bool> b(n);
        go(a,0,k,b);
        cout << endl;
    }
}

