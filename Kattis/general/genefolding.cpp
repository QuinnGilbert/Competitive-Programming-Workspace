#include <bits/stdc++.h>

using namespace std;

// To compute x^y under modulo m
long power(long long x,long long y,long long m){
    if (y == 0)return 1;
    long long p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    
    return (y % 2 == 0) ? p : (x * p) % m;
}

int main(){
    string s;
    cin>>s;
    vector<long long> f(s.size()+2);
    vector<long long> b(s.size());
    long long pow = 29;
    long long p=1;
    long long mod = 1'000'000'000;
    for(int i=0;i<s.size();i++){
        f[i+1]=(f[i]+p*(s[i]-'A'))%mod;
        p=(p*pow)%mod;
    }
    p=1;
    for(int i=s.size()-1;i>=0;i--){
        b[i+1]=(b[i+2]+p*(s[i]-'A'))%mod;
        p=(p*pow)%mod;
    }
    int start=0;
    //AAAA
    //0 0
    //1 0
    //1 2
    for(int i=0;i<s.size()&&i+(i-start+1)<s.size();i++){
        long long hash1 = (f[i+1]-f[start]+mod)%mod;
        int length = i-start+1;
        long long hash2 = (b[i+length+1]-b[i+length*2]+mod)%mod;
        if(hash1==hash2){
            start=i+1;
        }
    }
    int end = s.size()-1;
    for(int i=s.size()-1;i-(i-end+1)>=start;i--){
        long long hash1 = (b[i+1]-b[end]+mod)%mod;
        int length = end-i+1;
        long long hash2 = (f[i+1-length]-b[i-length*2]+mod)%mod;
        if(hash1==hash2){
            end--;
        }
    }
    cout<<start+s.size()-1-end<<endl;
}