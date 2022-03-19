#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    //default set only allows you to get the greater value
    set<int> less;
    set<int> greater;
    less.insert(100);
    greater.insert(100);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        less.insert(-x);
        greater.insert(x);
        cout<<-*less.upper_bound(-x)<<" "<<*greater.upper_bound(x)<<endl;
    }

}