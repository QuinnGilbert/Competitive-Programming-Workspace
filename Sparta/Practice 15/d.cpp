//This code is dedicated to Cameron Custer
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int main(){

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int a,b;
    cin>>a>>b;
    int count=0;
    while(a>b){
        if(a%2==0){
            a/=2;
        }else{
            a++;
        }
        count++;
    }
    cout<<count+b-a<<endl;

}