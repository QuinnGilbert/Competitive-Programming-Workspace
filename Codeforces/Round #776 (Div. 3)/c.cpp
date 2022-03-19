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

        int n;int m;
        cin>>n>>m;
        vector<tuple<int,int,int>> a(m);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            a[i]=make_tuple(y,x,i);
        }

        sort(a.begin(),a.end());

        vector<pair<int,int>> b;
        int sum=0;
        for(int i=0;i<2*n;i++){
            //check this line
            b.emplace_back(get<1>(a[i]),get<2>(a[i]));
            sum+=get<0>(a[i]);
            // cout<<get<1>(a[i])<<" "<<get<2>(a[i])<<" ";
            // cout<<b[i].first<<" "<<b[i].second<<" ";
        }
        // cout<<endl;

        sort(b.begin(),b.end());

        // for(int i=0;i<b.size();i++){
        //     cout<<b[i].first<<" "<<b[i].second<<" ";
        // }
        // cout<<endl;

        cout<<sum<<endl;
        for(int i=0;i<n;i++){
            cout<<b[i].second+1<<" "<<b[2*n-i-1].second+1<<endl;
        }

        cout<<endl;

    }

}