#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;cin>>n>>m;

    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    vector<vector<vector<int>>> v(n,vector<vector<int>>(m,vector<int>(4)));
    vector<pair<int,int>> dirs = {make_pair(-1,0),make_pair(1,0),make_pair(0,-1),make_pair(0,1)};
    //up down left right

    auto function = [&](int i, auto &&function)->void{

    };

    auto dfs = [&](int i, int j, int prev, auto &&dfs)->bool{

        // cout<<i<<" "<<j<<" "<<prev<<endl;
        
        if(i<0||j<0||i>=n||j>=m) return true;

        if(v[i][j][prev]) return false;

        v[i][j][prev]=true;
        vector<int> dir;

        // cout<<i<<" "<<j<<" "<<prev<<endl;

        if(a[i][j]=='.'){
            dir = {0,1,2,3};
        }else if(a[i][j]=='/'){
            if(prev==1||prev==3){
                dir = {0,2};
            }else{
                dir = {1,3};
            }
        }else if(a[i][j]=='\\'){
            if(prev==0||prev==3){
                dir = {1,2};
            }else{
                dir = {0,3};
            }
        }

        // cout<<i<<" "<<j<<" "<<prev<<endl;

        bool ret = false;
        for(int index:dir){
            auto d = dirs[index];
            if(dfs(i+d.first,j+d.second,index,dfs)){
                ret = true;
            }
        }

        // cout<<i<<" "<<j<<" "<<prev<<endl;

        return ret;

    };

    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int d=0;d<4;d++){
                if(!v[i][j][d]){
                    // cout<<i<<" "<<j<<" "<<d<<endl;
                    count+=!dfs(i,j,d,dfs);
                }
            }
        }
    }

    cout<<count<<endl;
    
}

// for / coming from right or down can go right or down
// for \ coming from right or up can go right or up

/*

2 2
/\
\/

*/