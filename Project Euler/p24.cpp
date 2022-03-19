#include <bits/stdc++.h>

using namespace std;

vector<string> perms;

int main(){

    int a[] = {0,1,2,3,4,5,6,7,8,9};
    do{
        string res="";
        for(int i=0;i<10;i++){
            res+=to_string(a[i]);
        }
        // cout<<res<<endl;
        perms.push_back(res);
    }while(next_permutation(a,a+10));
    sort(perms.begin(),perms.end());

    // for(string i:perms){
    //     cout<<i<<endl;
    // }

    cout<<perms[1'000'000-1];

}