#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;
    for(int test=0;test<t;test++){
        long long a,b;
        cin>>a>>b;
        long long mult;
        if(a%2==0){
            mult=1;
        }else{
            mult=-1;
        }
        long long x;
        if(b%4==0){
            x=0;
        }else if(b%4==1){
            x=-b;
        }else if(b%4==2){
            x=1;
        }else{
            x=b+1;
        }
        x=x*mult;
        
        cout<<a+x<<endl;
    }

}
// 0 01 02 03 04 05 06 07 08 09 10
// 0 -1  1  4  0 -5  1  8  0 -9  1