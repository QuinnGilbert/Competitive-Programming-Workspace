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
        vector<int> result;
        long long v = 1;
        result.push_back(v);
        bool no = false;
        for(int i=1;i<n;i++){
            v = v*3;
            if(v>1'000'000'000){
                no=true;
                break;
            }
            result.push_back(v);
        }
        if(no){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                cout<<result[i]<<" ";
            }
            cout<<endl;
        }
    }

}
/*

1 3 9 

x - 3 - 3 = 3


2 6
4 4

*/