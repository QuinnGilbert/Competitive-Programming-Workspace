#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int count=0;

        set<int> a;
        // a.max_load_factor(.25);
        // a.reserve(512);
        for(int i=0;i<n;i++){
            int x;cin>>x;
            if(!a.count(x)){
                count++;
                a.insert(x);
            }
        }

        // for(int i=0;i<count;i++){
        //     cout<<count<<' ';
        // }
        // for(int i=count;i<n;i++){
        //     count++;
        //     cout<<count<<' ';
        // }
        for(int i=0;i<n;i++){
            cout<<max(i+1,count)<<" ";
        }

        cout<<'\n';
    }

}