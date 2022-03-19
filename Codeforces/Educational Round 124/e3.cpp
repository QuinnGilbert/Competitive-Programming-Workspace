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
    int n;cin>>n;
    long long ans=0;
    for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            for(int L=0;L<n;L++){
                for(int R=L;R<n;R++){
                    ans+= r-l+1;
                    ans+= R-L+1;
                }
            }
            // ans+=r-l+1;
        }
    }
    cout<<ans<<endl;

}

/*

5+4+4+3+3+3+2+2+2+2+1+1+1+1+1

*/