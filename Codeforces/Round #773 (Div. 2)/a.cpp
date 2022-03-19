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
        vector<int> x(3);
        vector<int> y(3);
        long long length=0;
        for(int i=0;i<3;i++){
            cin>>x[i]>>y[i];
        }
        if(y[0]==y[1]&&y[2]<y[1]){
            length+=abs(x[0]-x[1]);
        }
        if(y[1]==y[2]&&y[0]<y[1]){
            length+=abs(x[1]-x[2]);
        }
        if(y[0]==y[2]&&y[1]<y[0]){
            length+=abs(x[0]-x[2]);
        }
        cout<<length<<endl;
    }

}