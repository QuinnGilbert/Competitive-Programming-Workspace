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
        string s;cin>>s;
        bool r = false,b=r,g=r;
        bool check = true;
        for(int i=0;i<6;i++){
            if(s[i]=='r') r = true;
            if(s[i]=='b') b = true;
            if(s[i]=='g') g = true;
            if(s[i]=='R'&&!r) check = false;
            if(s[i]=='B'&&!b) check = false;
            if(s[i]=='G'&&!g) check = false;
        }
        if(check){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

}