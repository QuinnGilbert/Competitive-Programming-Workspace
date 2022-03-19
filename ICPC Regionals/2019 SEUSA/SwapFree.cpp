#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;cin>>n;
    vector<string> a(n);
    for(string &s:a){
        cin>>s;
    }
    int m = a[0].length();

    vector<vector<int>> edge(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int count=0;
            for(int k=0;k<m;k++){
                if(a[i][k]==a[j][k]) count++;
            }
            if(count==m-2){
                edge[i].push_back(j);
                edge[j].push_back(i);
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     cout<<i<<":"<<endl;
    //     for(int j:edge[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<bool> v(n);
    
    


}