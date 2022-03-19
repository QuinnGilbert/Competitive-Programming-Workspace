#include <bits/stdc++.h>

using namespace std;

// unordered_map<int,bool> prime;

bool isPrime(int x){
    // if(prime.count(x)) return prime[x];
    if(x==1) return true;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            // prime[x]=false;
            return false;
        }
    }
    // prime[x] = true;
    return true;
}

int main(){
    // vector<bool> primes(1'000'000'000);
    // // for(int i=0;i<primes;i++){

    // // }


    int i=5;
    while(true){
        if(!isPrime(i)){
            bool check = false;
            for(int j=1;2*j*j<i;j++){
                if(isPrime(i-2*j*j)){
                    check = true;
                    // cout<<i<<" "<<j<<" "<<i-2*j*j<<endl;
                    break;
                }
            }
            if(!check){
                cout<<i<<endl;
                break;
            }
        }
        if((i-1)%6'000==0){
            cout<<i<<endl;
            break;
        }
        i+=2;
    }

}