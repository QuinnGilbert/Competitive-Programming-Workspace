#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x){
    if(x==1)return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}

int main(){

    int sum=0;
    int count=0;
    int i=11;
    while(count<11){
        bool check = isPrime(i);
        string s = to_string(i);
        for(int i=1;i<s.size();i++){
            int x = stoi(s.substr(0,i));
            if(!isPrime(x)) check = false;
            x = stoi(s.substr(i));
            if(!isPrime(x)) check = false;
        }
        if(check){
            cout<<i<<endl;
            sum+=i;
            count++;
        }
        i++;
    }
    cout<<sum<<endl;
}

//93 184 276 368

//932718654