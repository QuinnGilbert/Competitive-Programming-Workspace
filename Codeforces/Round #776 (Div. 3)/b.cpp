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

    int t;cin>>t;
    while(t--){
        int l,r,x;cin>>l>>r>>x;

        if(l/x==r/x){
            cout<<r/x+r%x<<endl;
        }else{
            int a = x*(r/x)-1;
            int b = r;
            // cout<<a<<" "<<b<<endl;

            cout<<max(a/x+a%x,b/x+b%x)<<endl;
        }
    }

}

// +1+1+1-2+1+1+1-2

// answer will either be greatest value, or greatest multiple of 4-1 (if no multiple of 4 should always be greatest value)