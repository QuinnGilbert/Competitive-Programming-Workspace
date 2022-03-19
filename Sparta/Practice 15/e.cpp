#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

bool isPrime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}

//int max=600

int main(){

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n = 3*100000;
    int max=0;
    int count=0;
    for(int i=2;i<n;i++){
        if(isPrime(i)){
            if(count>max){
                max=count;
                cout<<i<<" "<<max<<endl;
            }
            count=0;
        }else{
            count++;
        }
    }
    cout<<max<<endl;
}


/*
only need to add at most 1 to each number for each, which can be done easilly in n^2

1
2
3
4
5
6
7
8
9
10

2

for numbers above 600, there will be less than 600 multiples of k

for numbers below 600, we can simply precalculate the numbers at all mods under 600 and change those numbers for all mods

*/