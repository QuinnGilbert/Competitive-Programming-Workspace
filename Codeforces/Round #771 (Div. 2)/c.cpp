#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]--;
        }
        vector<bool> b(n);
        int index=0;
        int count=0;
        for(int i=0;i<n;i++){
            b[a[i]]=true;
            while(index<n&&b[index]){
                index++;
            }
            if(index==i+1) count++;
        }
        cout<<count<<"\n";
    }

}

/*

3 2 1 6 5 4

3 2 1 4 6 5

2 1 4 3


*/