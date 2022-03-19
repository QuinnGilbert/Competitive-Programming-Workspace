#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int min(int a,int b){
    if(a==-1||b<a)return b;
    return a;
}


int main(){

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n,m;
    cin>>n>>m;
    vector<string> a;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> count(n);
    for(int i=n-1;i>=0;i-=2){
        for(int j=0;j<m;j++){
            if(a[i][j]=='#')count[i]++;
            if(a[i-1][j]=='#')count[i]++;
        }
    }
    
    vector<vector<int>> dp(n/2,vector<int>(1<<(m-1)));
    for(int row = n-1;row>=0;row-=2){
        for(int i=0;i<(1<<(m-1));i++){
            //test if covers all cans in this row
            bool check = true;
            int c=0;
            int x = i;
            int index=0;
            int prev=0;
            while(x>=0){
                if(x%2==1){
                    if(prev){
                        check = false;
                        break;
                    }
                    if(a[row][index]=='#')c++;
                    if(a[row][index+1]=='#')c++;
                    if(a[row-1][index]=='#')c++;
                    if(a[row-1][index+1]=='#')c++;
                }
                prev=x%2;
                index++;
                x/=2;
            }
            if(!check||c!=count[row]){
                dp[row][i]=-1;
                continue;
            }
            for(int j=0;j<(1<<(m-1));j++){
                
            }
        }
    }

}