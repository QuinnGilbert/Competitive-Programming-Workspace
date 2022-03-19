#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    if(b[0]<a[0]){
        cout<<0<<endl;
        return 0;
    }
    int t = b[0]-a[0]+1;
    for(int i=1;i<n;i++){
        if(a[i]>=b[i]){
            cout<<t-1;
            return 0;
        }else if(b[i]-a[i]+1<t){
            cout<<t-1;
            return 0;
        }else if(b[i]-a[i]>=t){
            break;
        }else if(b[i]-a[i]==t-1&&i==n-1){
            cout<<t-1;
            return 0;
        }
    }
    cout<<t<<endl;
}

