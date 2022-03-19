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

    vector<string> a(3);
    vector<string> b(3);

    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    for(int i=0;i<3;i++){
        cin>>b[i];
    }

    vector<int> freqa(26);
    vector<int> freqb(26);
    int green=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            green+=(a[i][j]==b[i][j]);
            freqa[a[i][j]-'A']++;
            freqb[b[i][j]-'A']++;
        }
    }
    int yellow=0;
    for(int i=0;i<26;i++){
        yellow+=min(freqa[i],freqb[i]);
    }
    cout<<green<<endl;
    cout<<yellow-green<<endl;


}