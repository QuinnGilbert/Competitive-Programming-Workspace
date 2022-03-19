#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin>>s;
    vector<bool> a(26);
    bool check = false;
    for(int i=0;i<s.length();i++){
        if(a[s[i]-'a']) check = true;
        a[s[i]-'a'] = true;
    }
    cout<<!check<<endl;

}