#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x){
    if(x==1) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

bool perm(int a,int b,int c){
    string x = to_string(a);
    string y = to_string(b);
    string z = to_string(c);
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(z.begin(),z.end());
    return x==y&&y==z;
}

int main(){

    string test = "cbabc";
    string test2 = "abbcc";
    sort(test.begin(),test.end());
    bool check = test==test2;
    cout<<check<<"\n";


    for(int i=1000;i<=9999;i++){
        for(int j=1;j<=10000;j++){
            if(perm(i,i+j,i+2*j)&&isPrime(i)&&isPrime(i+j)&&isPrime(i+2*j)){
                cout<<i<<" "<<i+j<<" "<<i+2*j<<"\n";
            }
        }
    }

}


//