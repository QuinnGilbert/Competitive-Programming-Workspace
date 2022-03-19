#include <bits/stdc++.h>

using namespace std;

void go(int div, long long res, int n){
    if(div==n+1){
        cout<<res<<endl;
        return;
    }
    for(int i=0;i<10;i++){
        if(i==0&&res==0)continue;
        long long x = res*10+i;
        if(x%div==0){
            go(div+1,x,n);
        }
    }
}    

int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n;
        cin>>n;
        go(1,0,n);

    }
}

