#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x){
    if(x==1)return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

bool pan(int x){
    string s = to_string(x);
    int n = s.size();
    if(s.size()!=n) return false;
    vector<bool> a(10);
    for(char i:s){
        a[i-'0']=true;
    }
    for(int i=1;i<=n;i++){
        if(!a[i]) return false;
    }
    return true;
}

int main(){
    int max=0;
    for(int i=2;i<1'000'000'000;i++){
        if(pan(i)&&isPrime(i)){
            max = i;
            cout<<max<<endl;
        }
    }
}

//7652413
