#include <bits/stdc++.h>

using namespace std;

int main(){

    string s = "";
    int i=0;
    while(s.size()<=1000000){
        s+=to_string(i);
        i++;
    }
    cout<<s.substr(0,101)<<endl;
    cout<<s[1]+s[10]+s[100]+s[1000]+s[10000]+s[100000]+s[1000000]<<endl;
    cout<<s[1]<<" "<<s[10]<<" "<<s[100]<<" "<<s[1000]<<" "<<s[10000]<<" "<<s[100000]<<" "<<s[1000000]<<endl;

}