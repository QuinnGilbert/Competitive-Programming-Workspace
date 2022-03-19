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
        bool yes = true;
        if(x%(d*d)!=0){
            yes = false;
        }
        if(d<=1000&&x%(d*d*d)==0&&isPrime(d)){
            yes = false;
        }
        if(isPrime(x/(d*d))){
            yes = false;
        }
        if(d<=1000&&x%(d*d*d*d)==0){
            int count=0;
            for(int i=2;i*i<=d;i++){
                if(d%i==0){
                    if(i*i==d){
                        count++;
                    }else{
                        count+=2;   
                    }
                }
            }
            if(count==1){
                yes=false;
            }
        }


        if(yes){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

}

//can just try all divisors and test if both are beautiful

/*

beautiful numbers are divisible by d but not d^2

we need to find a way to divide x by a beautful number and get another beautiful number

x must be divisible by d^2 (not beautiful)

x must not be equal to d^2 * prime (or 1)



x must not be divisible by d^4 is d has only one divisor besides itself and 1

x must not be divisible by d^3 is d is prime
*/