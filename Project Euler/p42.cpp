#include <bits/stdc++.h>

using namespace std;

int main(){

    ifstream fin("words.txt");
    unordered_set<int> all;
    int i=1;
    int x=0;
    while(x<1300){
        x+=i;
        all.insert(x);
    }
    int count=0;
    string s;
    fin>>s;
    i=1;
    while(i<s.size()-1){
        for(char c:s){
            count+=(c-'A');
        }
        if(all.count(i)){
            count++;
            cout<<s<<count<<endl;
        }
    }
    cout<<count<<endl;
}