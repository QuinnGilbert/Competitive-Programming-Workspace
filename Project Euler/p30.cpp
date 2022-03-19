#include <bits/stdc++.h>

using namespace std;

int main(){

    int count=0;
    for(int i=2;i<1'000'000;i++){
        string s = to_string(i);
        int sum=0;
        for(char j:s){
            sum+=pow(j-'0',5);
        }
        if(sum==i){
            count+=i;
            cout<<i<<endl;
        }
    }
    cout<<count<<endl;
}