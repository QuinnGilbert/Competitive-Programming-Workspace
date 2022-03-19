#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x){
    if(x==1) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

int main(){

    vector<int> primes;
    for(int i=2;i<1'000'000;i++){
        if(isPrime(i)){
            primes.push_back(i);
        }
    }

    for(int i=0;i<1'000'000;i++){
        bool check = true;
        for(int k=0;k<4;k++){
            i=i+k;
            int count=0;
            for(int j:primes){
                if(j>i) break;
                if(i%j==0)count++;
            }
            if(count<4) check = false;
            i=i-k;
        }
        if(check){
            cout<<i<<endl;
            break;
        }
        if(i%1000==0)cout<<i<<endl;
    }

}