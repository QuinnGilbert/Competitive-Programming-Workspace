#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

int main(){

    int count=0;
    for(int i=2;i<1'000'000;i++){
        int x = i%10*pow(10,to_string(i).size()-1)+i/10;
        bool check = isPrime(i);
        while(x!=i&&check){
            if(!isPrime(x))check = false;
            x=x%10*pow(10,to_string(x).size()-1)+x/10;
        }
        if(check)count++;
    }
    cout<<count<<endl;

}