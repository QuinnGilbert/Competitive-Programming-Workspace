#include <bits/stdc++.h>

using namespace std;

int main(){

    int sum=1;
    int x=1;
    int v=2;
    for(int i=0;i<500;i++){
        for(int j=0;j<4;j++){
            x+=v;
            sum+=x;
            cout<<x<<endl;
        }
        v+=2;
    }
    cout<<sum<<endl;
}