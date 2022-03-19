#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x = 1;
    long long y = 1;
    int count=1;
    int index=1;
    while(count<1000){
        if(x>10'000'000'000){
            x/=100'000;
            y/=100'000;
            count+=5;
        }
        if(count+log(x)/log(10)>=1000){
            cout<<index<<endl;
            break;
        }
        cout<<x<<endl;
        long long temp = y;
        y=x+y;
        x=temp;
        index++;
    }

}