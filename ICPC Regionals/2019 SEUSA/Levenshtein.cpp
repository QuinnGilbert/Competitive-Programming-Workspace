#include <bits/stdc++.h>

using namespace std;

int main(){

    string a,b;
    cin>>a>>b;
    set<string> res;
    for(char c: a){
        
        for(int i=0;i<b.size();i++){
            string temp = b.substr(0,i) + c + b.substr(i,b.size()-i);
            res.insert(temp);
            temp = b.substr(0,i) + c + b.substr(i+1,b.size()-i-1);
            res.insert(temp);
            temp = b.substr(0,i) + b.substr(i+1,b.size()-i-1);
            res.insert(temp);
        }

        res.insert(b+c);


    }

    for(string i:res){
        if(i!=b)cout<<i<<endl;
    }

}