#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

bool beats(vector<int> a,vector<int> b){
    int wins=0;
    int loss=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(a[i]>b[j]){
                wins++;
            }else if(b[j]>a[i]){
                loss++;
            }
        }
    }
    return wins>loss;
}

int main(){

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;cin>>t;
    while(t--){
        vector<int> a(4);
        vector<int> b(4);
        for(int i=0;i<4;i++){
            cin>>a[i];
        }
        for(int i=0;i<4;i++){
            cin>>b[i];
        }
        bool yes = false;
        for(int i=1;i<=10;i++){
            for(int j=1;j<=10;j++){
                for(int k=1;k<=10;k++){
                    for(int l=1;l<=10;l++){
                        //a beats c, c beats b, b beats a
                        //c beats a, b beats c, a beats b
                        vector<int> c = {i,j,k,l};
                        if(beats(a,c)&&beats(c,b)&&beats(b,a)) yes = true;
                        if(beats(c,a)&&beats(b,c)&&beats(a,b)) yes = true;
                    }
                }
            }
        }
        if(yes){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }

}