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

        // int count=0;
        // for(int i=2;i*i<=x;i++){
        //     if(x%i==0){
        //         int a = i;
        //         int b = x/i;

        //         if(a%d==0&&a%(d*d)!=0  &&  b%d==0&&b%(d*d)!=0){
        //             count++;
        //         }
        //     }
        // }

        // int count=0;
        // for(int i=2;i*i<d;i++){
        //     if(d%i==0){
        //         int a = i;
        //         int b = d/i;
        //         if(isPrime(a)){
        //             count++;
        //         }
        //         if(isPrime(b)){
        //             count++;
        //         }
        //     }
        // }

        // int count2=0;
        // while(x%d==0){
        //     x/=d;
        //     count2++;
        // }



        // if(isPrime(x)||(count2==3&&count==1)){
        //     cout<<"NO"<<endl;
        // }else{
        //     cout<<"YES"<<endl;
        // }
    }

}

/*

beautiful numbers are divisible by d but not d^2

x%d^4==0, it is always true unless x is only a power of d AND d is prime

x%d^3==0, it is always true unless remainder is equal to sqrt(d) and d is prime


*/