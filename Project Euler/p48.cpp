#include<bits/stdc++.h>

using namespace std;

int main(){

    long long sum = 0;
    for(int i=1;i<=1000;i++){
        long long x = 1;
        for(int j=0;j<i;j++){
            x*=i;
            x%=10'000'000'000;
        }
        sum+=x;
    }
    cout<<sum<<endl;

}
//9110846700