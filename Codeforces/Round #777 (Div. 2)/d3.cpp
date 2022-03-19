#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

bool isPrime(long long x){
    if(x==1) return true;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;cin>>t;
    while(t--){
        long long x,d;cin>>x>>d;

        // cout<<t<<endl;
        int pow=0;
        int remainder=x;
        while(remainder%d==0){
            remainder/=d;
            pow++;
        }
        if(pow>=4){
            if(isPrime(d)&&isPrime(remainder)){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }else if(pow==3){
            if(isPrime(d)&&isPrime(remainder)||remainder==sqrt(d)&&isPrime(sqrt(d))){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }else if(pow==2){
            if(isPrime(remainder)){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }
        }else{
            cout<<"NO"<<endl;
        }


    }

}

/*

beautiful numbers are divisible by d but not d^2

x%d^4==0, it is always true unless x is only a power of d AND d is prime

x%d^3==0, it is always true unless remainder is equal to sqrt(d) and d is prime


*/