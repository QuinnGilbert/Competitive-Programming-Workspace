#include <bits/stdc++.h>

using namespace std;

long long MOD = 998244353;

long long solve(string s){
    int n = s.length();
        
}

bool check(string s){
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]) return false;
    }
    return true;
}

int main(){

    string s;
    string e;
    cin>>s>>e;
    cout<<solve(e)-solve(s)+check(s);

}