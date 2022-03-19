#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x){
    if(x==1) return false;
    for(long long i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}

int main(){

    cout<<"CHECK"<<endl;
    vector<int> primes;
    vector<bool> prime(1'000'000);
    for(int i=2;i<=1'000'000;i++){
        if(isPrime(i)){
            primes.push_back(i);
            prime[i]=true;
        }
    }
    cout<<primes.size()<<"\n";

    vector<long long> sum(primes.size()+1);
    for(int i=1;i<primes.size();i++){
        sum[i]=sum[i-1]+primes[i-1];
    }

    int max=0;
    int value=0;
    for(int i=0;i<primes.size();i++){
        for(int j=i+max;j<primes.size();j++){
            if(sum[j+1]-sum[i]>=prime.size()){
                break;
            }
            if(prime[sum[j+1]-sum[i]]){
                max = j-i;
                value = sum[j+1]-sum[i];
            }
        }
    }
    cout<<max<<" "<<value<<"\n";
}

//~80,000 primes below 1 million (~10^5)