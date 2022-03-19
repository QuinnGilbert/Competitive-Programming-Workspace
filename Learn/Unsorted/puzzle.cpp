#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> dp;

int value(vector<vector<int>> &a){
    int p=1;
    int res=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            res+=p*a[i][j];
            p*=9;
        }
    }
    return res;
}

void print(vector<vector<int>> &a){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int cnt=0;

unordered_set<int> vis;

int dfs(vector<vector<int>> &a){

    // print(a);
    cout<<vis.size()<<" "<<dp.size()<<endl;
    cnt++;

    int val = value(a);
    vis.insert(val);
    if(dp.count(val)) return dp[val];
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int minim=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int d=0;d<4;d++){
                int x = dir[d][0]+i;
                int y = dir[d][1]+j;
                if(x<3&&x>=0&&y<3&&y>=0&&a[x][y]==0){
                    swap(a[i][j],a[x][y]);
                    if(!vis.count(value(a))){
                        minim=min(dfs(a),minim);
                    }
                    swap(a[i][j],a[x][y]);
                }
            }
        }
    }
    return dp[val]=1+minim;
}

int main(){
    int t;
    cin>>t;
    vector<vector<int>> res(3,vector<int>(3));
    int v=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            res[i][j]=v;
            v++;
        }
    }
    res[2][2]=0;
    dp[value(res)]=0;
    for(int q=0;q<t;q++){
        vector<vector<int>> a(3,vector<int>(3));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
        cout<<dfs(a);
    }
}
/*
3
1 2 3
4 5 6
7 8 0

1 2 3
7 0 4
8 6 5

4 2 6
3 1 5
7 0 8
*/