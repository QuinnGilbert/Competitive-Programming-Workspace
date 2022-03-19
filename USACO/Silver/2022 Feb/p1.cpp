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

    int n;cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    vector<vector<bool>> edge(n,vector<bool>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            a[i][j]--;
        }
        int index=0;
        while(a[i][index]!=i){
            edge[i][a[i][index]]=true;
            index++;
        }
        // edge[i][i] = true;
    }

    // cout<<"CHECK"<<endl;

    vector<bool> v(n);
    vector<vector<bool>> path(n,vector<bool>(n));

    // boolean[][] path = new boolean[n][n];

    auto dfs = [&](int cur, int start, auto &&dfs)->void{
        v[cur] = true;
        path[start][cur] = true;
        // cout<<cur<<" "<<target<<endl;
        for(int i=0;i<n;i++){
            if(edge[cur][i]&&!v[i]){
                dfs(i,start,dfs);
            }
        }
    };

    // cout<<"CHECK"<<endl;

    for(int i=0;i<n;i++){
        v = vector<bool>(n);
        dfs(i,i,dfs);
    }

    // cout<<"CHECK"<<endl;

    for(int i=0;i<n;i++){
        // cout<<"i: "<<i<<endl;
        int index=0;
        while(!(a[i][index]==i||path[a[i][index]][i])){
            // cout<<"index: "<<index<<endl;
            index++;
        }
        // cout<<"i2: "<<i<<endl;
        cout<<a[i][index]+1<<"\n";
    }

    // cout<<"END"<<endl;

}

/*
We can give cow a item b if there is an edge between 
*/