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

        int n,d;cin>>n>>d;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int minv=INT_MAX;
        int mini=0;
        int prev=0;
        for(int i=0;i<n;i++){
            int gap=a[i]-prev-1;
            if(gap<minv){
                minv = gap;
                mini=i;
            }
            prev = a[i];
        }

        int ans = 0;
        vector<int> vals = {mini,mini-1};
        for(int index:vals){

            int maxBreak = INT_MIN;
            int minBreak = INT_MAX;
            prev=0;
            for(int i=0;i<n;i++){
                if(i!=index){
                    int gap = a[i]-prev-1;
                    if(gap>maxBreak){
                        maxBreak = gap;
                    }
                    if(gap<minBreak){
                        minBreak = gap;
                    }
                    prev = a[i];
                }
            }
            // cout<<minBreak<<" "<<(maxBreak-1)/2<<" "<<d-prev-1<<endl;
            ans = max(ans, min(minBreak, max( (maxBreak-1)/2, d-prev-1) ));

        }
        cout << ans << "\n";

    }

}