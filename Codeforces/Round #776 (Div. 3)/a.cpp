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
        char c;cin>>c;
        bool check=false;
        for(int i=0;i<s.size();i++){
            if(i%2==0&&s[i]==c) check = true;
        }
        if(check)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}

