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
        int n,x;
        cin>>n>>x;
        vector<int> a(n+1);
        vector<int> pre(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pre[i] = pre[i-1]+a[i];
        }

        vector<int> max(n+1,INT_MIN);
        max[0] = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int length = j-i;
                if(pre[j]-pre[i]>max[length]) max[length] = pre[j]-pre[i];
            }
        }

        for(int i=0;i<=n;i++){
            long long result = 0;
            for(int j=0;j<=n;j++){
                long long val = max[j] + min(j,i)*x;
                if(val>result){
                    result = val;
                }
            }
            cout<<result<<" ";
        }
        cout<<endl;

    }

}