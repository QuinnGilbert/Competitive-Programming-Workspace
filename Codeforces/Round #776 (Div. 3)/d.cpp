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

        int n;cin>>n;
        vector<int> a(n);
        for(auto &i:a){
            cin>>i;
        }
        
        vector<int> result(n+1);
        for(int i=n;i>0;i--){
            int index=0;
            for(int j=0;j<n;j++){
                if(a[j]==i){
                    index=j;
                }
            }
            int shifts = (i-1-index+i)%i;
            result[i] = (i-shifts+i)%i;

            vector<int> b = a;
            for(int j=0;j<i;j++){
                b[(j+shifts)%i] = a[j];
            }
            a=b;
            // for(int j=0;j<n;j++){
            //     cout<<a[j]<<" ";
            // }
            // cout<<endl;
        }
        for(int i=1;i<=n;i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;


    }


}


/*

3 2 5 6 1 4
1 4 3 2 5 6
1 4 3 2 5 6
3 2 1 4 5 6
2 1 3 4 5 6
1 2 3 4 5 6





*/