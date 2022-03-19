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
        int n,m;cin>>n>>m;
        vector<string> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<vector<int>> prefix(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prefix[i][j] = prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+(a[i-1][j-1]=='1');
            }
        }

        auto count = [&](int x1,int y1,int x2,int y2)->int{
            return prefix[x2+1][y2+1]-prefix[x1][y2+1]-prefix[x2+1][y1]+prefix[x1][y1];
        };

        bool check = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='1'){
                    int l=1;
                    int h=1;
                    while(j+l<m&&a[i][j+l]=='1'){
                        l++;
                    }
                    while(i+h<n&&count(i+h,j,i+h,j+l-1)==l){
                        h++;
                    }
                    if(i+h<n&&count(i+h,j,i+h,j+l-1)!=0){
                        check = false;
                    }
                    if(j+l<m&&count(i,j+l,i+h-1,j+l)!=0){
                        check = false;
                    }
                    if(i>0&&count(i-1,j,i-1,j+l-1)>0&&count(i-1,j,i-1,j+l-1)!=l){
                        check = false;
                    }
                }
            }
        }

        if(check){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

}