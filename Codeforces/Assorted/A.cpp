#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        int x = abs(a+c-2*b);
        cout<<x%3<<endl;
    }
}

