#include <bits/stdc++.h>

using namespace std;

string to_binary(int i){
    string result="";
    while(i!=0){
        result=to_string(i%2)+result;
        i/=2;
    }
    return result;
}

bool isPal(string s){
    for(int i=0;i<=s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1])return false;
    }
    return true;
}

int main(){

    int sum=0;
    for(int i=1;i<1'000'000;i++){
        if(i<100){
            cout<<i<<" "<<isPal(to_string(i))<<" "<<to_binary(i)<<endl;
        }
        if(isPal(to_string(i))&&isPal(to_binary(i)))sum+=i;
    }
    cout<<sum<<endl;
}