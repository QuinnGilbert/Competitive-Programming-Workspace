#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if(n<0){
        n*=-1;
    }
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

int main(){

    int max=0;
    int result=0;
    for(int a=-999;a<1000;a++){
        for(int b=-999;b<1000;b++){
            int n=0;
            while(isPrime(n*n+n*a+b)){
                // cout<<n<<endl;
                n++;
            }
            if(n>max){
                max=n;
                result=a*b;
            }
            // cout<<a<<b<<endl;
        }
    }
    cout<<result<<endl;
}

