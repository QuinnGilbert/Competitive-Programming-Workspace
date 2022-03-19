#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    string s;
    cin>>s;
    int index=0;
    for(int i=1;i<=n;i++){
        if(to_string(i)!=s.substr(index,to_string(i).length())){
            cout<<i<<endl;
            break;
        }
        index+=to_string(i).length();
    }

}