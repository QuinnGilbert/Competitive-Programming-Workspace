#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int x=0;
        for(int i=0;i<m;i++){
            x*=2;
            if(s[i]=='T'){
                x++;
            }
        }
        a[i] = x;
    }
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<endl;
    // }
    int max = 0;
    for(int i=0;i<pow(2,m);i++){
        int min = INT_MAX;
        for(int j=0;j<n;j++){
            int x = a[j];
            int y = i;
            int count=0;
            for(int k=0;k<m;k++){
                if(x%2==y%2){
                    count++;
                }
                x/=2;
                y/=2;
            }
            if(count<min){
                min=count;
            }
        }
        // if(min==4){
        //     cout<<i<<endl;
        // }
        if(min>max){
            max=min;
        }
    }
    cout<<max<<endl;
}