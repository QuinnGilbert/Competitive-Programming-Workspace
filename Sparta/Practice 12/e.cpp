#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,k;
    cin>>n>>k;
    vector<vector<vector<int>>> count(n);
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int total=0;
    do{
        int c=0;
        int ma=0;
        for(int i=0;i<n;i++){
            ma=max(ma,a[i]);
            if(ma>a[i])c++;
        }
        count[c].push_back(a);
        total++;
    }while(next_permutation(a.begin(),a.end()));
    int i=k;
    // for(int i=0;i<n;i++){
        cout<<count[i].size()<<"\n";
        for(vector<int> j : count[i]){
            for(int k:j){
                cout<<k<<" ";
            }
            cout<<endl;
        }
    // }
    // cout<<total<<endl;

}