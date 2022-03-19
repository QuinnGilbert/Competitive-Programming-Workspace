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
        int n,m,k,q;
        cin>>n>>m>>k>>q;
        vector<int> x(q);
        vector<int> y(q);
        for(int i=0;i<q;i++){
            cin>>x[i];
            cin>>y[i];
        }
        
        long long MOD = 998244353;
        long long result=1;
        unordered_set<int> allx;
        unordered_set<int> ally;
        for(int i=q-1;i>=0;i--){

            if(allx.count(x[i])&&ally.count(y[i])){
                continue;
            }
            result = (result*k)%MOD;
            allx.insert(x[i]);
            ally.insert(y[i]);
            if(allx.size()==n||ally.size()==m){
                break;
            }

        }

        cout<<result<<endl;

    }

}